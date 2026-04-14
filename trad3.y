/*
     Miguel del Valle Gassó, Mateo Nonzioli,717
100496753@alumnos.uc3m.es,100523033@alumnos.uc3m.es
*/

%{                          // SECTION 1 Declarations for C-Bison
#include <stdio.h>
#include <ctype.h>            // tolower()
#include <string.h>           // strcmp() 
#include <stdlib.h>           // exit()

#define FF fflush(stdout);    // to force immediate printing 

int yylex () ;
void yyerror () ;
char *my_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
void clear_local_vars();
void add_scoped_var(char *original, char *translated);
void add_local_var(char *name);
void add_param_var(char *name);
char *translated_name(char *name);

char temp [2048] ;

char current_function[256] = "";

typedef struct s_localvar {
    char *original;
    char *translated;
    struct s_localvar *next;
} t_localvar;

t_localvar *local_vars = NULL;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr     // stack of PDA has type t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identifier=variable
%token INTEGER       // token for integer type
%token STRING        // token for string type
%token MAIN          // token for keyword main 
%token WHILE         // token for keyword while
%token IF            // token for keyword if
%token ELSE          // token for keyword else
%token FOR INC DEC   // tokens for for keywords
%token SWITCH CASE DEFAULT BREAK // tokens for switch/case keywords
%token PUTS          // token for keyword puts
%token PRINTF        // token for keyword printf
%token AND OR NOT    // tokens for logical operators
%token EQ NE LE GE   // tokens for comparison operators (2-char)
%token RETURN        // token for return statement





%right '='                    // last operation to do 
%left OR                      // ||
%left AND                     // &&
%left EQ NE                   //== !=
%left '<' LE '>' GE           //<= >=
%left '+' '-'                 //
%left '*' '/' '%'             //
%right '^'                    //
%right NOT UNARY_SIGN         // highest precedence




%%

axiom:
      global_decls defs_before_main
      {
          printf("%s%s", $1.code, $2.code);
      }
    ;

defs_before_main:
      main_def
      {
          $$ = $1;
      }
    | function_def defs_before_main
      {
          sprintf(temp, "%s%s", $1.code, $2.code);
          $$.code = gen_code(temp);
      }
    ;

global_decls:                                { $$.code = gen_code(""); }
            | global_decls declaration ';'   { sprintf(temp, "%s%s\n", $1.code, $2.code);
                                               $$.code = gen_code(temp); }
            ;

main_def:
      MAIN '(' ')' 
      {
          strcpy(current_function, "main");
          clear_local_vars();
      }
      '{' body '}'
      {
          sprintf(temp, "(defun main ()\n%s)\n", $6.code);
          $$.code = gen_code(temp);
          clear_local_vars();
          strcpy(current_function, "");
      }
    ;

function_def:
      IDENTIF
      {
          strcpy(current_function, $1.code);
          clear_local_vars();
      }
      '(' param_defs ')' '{' body '}'
      {
          sprintf(temp, "(defun %s (%s)\n%s)\n", $1.code, $4.code, $7.code);
          $$.code = gen_code(temp);
          clear_local_vars();
          strcpy(current_function, "");
      }
    ;

param_defs:
      {
          $$.code = gen_code("");
      }
    | param_list
      {
          $$ = $1;
      }
    ;

param_list:
      INTEGER IDENTIF
      {
          add_param_var($2.code);
          $$.code = gen_code($2.code);
      }
    | param_list ',' INTEGER IDENTIF
      {
          add_param_var($4.code);
          sprintf(temp, "%s %s", $1.code, $4.code);
          $$.code = gen_code(temp);
      }
    ;

call_args:
      {
          $$.code = gen_code("");
      }
    | call_arg_list
      {
          $$ = $1;
      }
    ;

call_arg_list:
      expression
      {
          $$ = $1;
      }
    | call_arg_list ',' expression
      {
          sprintf(temp, "%s %s", $1.code, $3.code);
          $$.code = gen_code(temp);
      }
    ;

body:
      body_element
      {
          sprintf(temp, " %s\n", $1.code);
          $$.code = gen_code(temp);
      }
    | body body_element
      {
          sprintf(temp, "%s %s\n", $1.code, $2.code);
          $$.code = gen_code(temp);
      }
    ;

body_element:
      statement
      {
          $$.code = $1.code;
      }
    | declaration ';'
      {
          $$.code = $1.code;
      }
    ;

statement:  sentence ';'                { sprintf(temp, "%s", $1.code);
                                          $$.code = gen_code(temp); }
            | control_struct            { sprintf(temp, "%s", $1.code);
                                          $$.code = gen_code(temp); }
            ;

control_struct: WHILE '(' expression ')' '{' body '}'                             { sprintf (temp, "(loop while %s do %s)", $3.code, $6.code) ;  
                                                                                    $$.code = gen_code (temp) ; }
                | IF '(' expression ')' '{' body '}'                              { sprintf (temp, "(if %s (progn %s))", $3.code, $6.code) ;  //!ASK ABOUT PROGN!
                                                                                    $$.code = gen_code (temp) ; }
                | IF '(' expression ')' '{' body '}' ELSE '{' body '}'            { sprintf (temp, "(if %s (progn %s) (progn %s))", $3.code, $6.code, $10.code) ;  //!ASK ABOUT PROGN!
                                                                                    $$.code = gen_code (temp) ; } 
                | FOR '(' for_init ';' expression ';' for_update ')' '{' body '}' { sprintf (temp, "(progn %s (loop while %s do (progn %s %s)))", $3.code, $5.code, $10.code, $7.code) ;
                                                                                    $$.code = gen_code (temp) ; } 
                | SWITCH '(' expression ')' '{' case_list '}'                     { sprintf (temp, "(case %s %s)", $3.code, $6.code) ;
                                                                                    $$.code = gen_code (temp) ; }
            ;

case_list:  case_list case_block            { sprintf(temp, "%s %s", $1.code, $2.code);
                                              $$.code = gen_code(temp) ; }
            | case_block                    { $$.code = $1.code ; }
            ;

case_block:  CASE NUMBER ':' body BREAK ';'     { sprintf(temp, "(%d (progn %s))", $2.value, $4.code);
                                                  $$.code = gen_code(temp) ; }
            | DEFAULT ':' body BREAK ';'        { sprintf(temp, "(otherwise (progn %s))", $3.code);
                                                  $$.code = gen_code(temp) ; }
            ;

for_init:
      IDENTIF '=' expression
      {
          char *name = translated_name($1.code);
          sprintf(temp, "(setf %s %s)", name, $3.code);
          $$.code = gen_code(temp);
      }
    ;

for_update:
      INC '(' IDENTIF ')'
      {
          char *name = translated_name($3.code);
          sprintf(temp, "(setf %s (+ %s 1))", name, name);
          $$.code = gen_code(temp);
      }
    | DEC '(' IDENTIF ')'
      {
          char *name = translated_name($3.code);
          sprintf(temp, "(setf %s (- %s 1))", name, name);
          $$.code = gen_code(temp);
      }
    ;

declaration:  INTEGER decl_list              { $$ = $2 ; }
            ;

decl_list:    decl_item                      { $$ = $1 ; }
            | decl_list ',' decl_item        { sprintf (temp, "%s\n%s", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            ;

decl_item:
      IDENTIF
      {
          char *name;
          if (strlen(current_function) > 0) {
              add_local_var($1.code);
              name = translated_name($1.code);
          } else {
              name = gen_code($1.code);
          }

          sprintf(temp, "(setq %s 0)", name);
          $$.code = gen_code(temp);
      }
    | IDENTIF '=' NUMBER
      {
          char *name;
          if (strlen(current_function) > 0) {
              add_local_var($1.code);
              name = translated_name($1.code);
          } else {
              name = gen_code($1.code);
          }

          sprintf(temp, "(setq %s %d)", name, $3.value);
          $$.code = gen_code(temp);
      }
    | IDENTIF '[' NUMBER ']'
      {
          char *name;
          if (strlen(current_function) > 0) {
              add_local_var($1.code);
              name = translated_name($1.code);
          } else {
              name = gen_code($1.code);
          }

          sprintf(temp, "(setq %s (make-array %d))", name, $3.value);
          $$.code = gen_code(temp);
      }
    ;
sentence:
      IDENTIF '=' expression
      {
          char *name = translated_name($1.code);
          sprintf(temp, "(setf %s %s)", name, $3.code);
          $$.code = gen_code(temp);
      }
    | IDENTIF '[' expression ']' '=' expression
      {
          char *name = translated_name($1.code);
          sprintf(temp, "(setf (aref %s %s) %s)", name, $3.code, $6.code);
          $$.code = gen_code(temp);
      }
    | RETURN expression
      {
          sprintf(temp, "(return-from %s %s)", current_function, $2.code);
          $$.code = gen_code(temp);
      }
    | PRINTF '(' STRING ',' arg_list ')'
      {
          $$.code = $5.code;
      }
    | PUTS '(' STRING ')'
      {
          sprintf(temp, "(print \"%s\")", $3.code);
          $$.code = gen_code(temp);
      }
    | expression
      {
          $$ = $1;
      }
    ;
          
arg_list:   arg                             {sprintf (temp, "(princ %s)", $1.code) ; 
                                               $$.code = gen_code (temp) ;}
            | arg_list ',' arg              {sprintf (temp, "%s\n(princ %s)", $1.code, $3.code) ; 
                                               $$.code = gen_code (temp) ;}
            ;

arg:        expression                      {$$ = $1 ; }
            | STRING                        {sprintf (temp, "\"%s\"", $1.code) ; 
                                               $$.code = gen_code (temp) ;}
            ;

expression:   term                           { $$ = $1 ; }
            | expression '+' expression      { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '-' expression      { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '*' expression      { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '/' expression      { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '%' expression      { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '^' expression      { sprintf (temp, "(expt %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression AND expression      { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression OR expression       { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | NOT expression                 { sprintf (temp, "(not %s)", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression EQ expression       { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression NE expression       { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '<' expression      { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression LE expression       { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '>' expression      { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression GE expression       { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            ;

term:         operand                        { $$ = $1 ; }                          
            | '+' operand %prec UNARY_SIGN   { $$ = $2 ; }
            | '-' operand %prec UNARY_SIGN   { sprintf (temp, "(- %s)", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            ;

operand:
      IDENTIF '(' call_args ')'
      {
          if (strlen($3.code) == 0)
              sprintf(temp, "(%s)", $1.code);
          else
              sprintf(temp, "(%s %s)", $1.code, $3.code);

          $$.code = gen_code(temp);
      }
    | IDENTIF '[' expression ']'
      {
          char *name = translated_name($1.code);
          sprintf(temp, "(aref %s %s)", name, $3.code);
          $$.code = gen_code(temp);
      }
    | IDENTIF
      {
          char *name = translated_name($1.code);
          sprintf(temp, "%s", name);
          $$.code = gen_code(temp);
      }
    | NUMBER
      {
          sprintf(temp, "%d", $1.value);
          $$.code = gen_code(temp);
      }
    | '(' expression ')'
      {
          $$ = $2;
      }
    ;


%%                           // SECTION 4    Code in C

int n_line = 1 ;

void yyerror (char *message)
{
    fprintf (stderr, "%s in line %d\n", message, n_line) ;
    printf ( "\n") ;
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)     // reserve n bytes of dynamic memory 
{
    char *p ;
    static long int nb = 0 ;     // used to count the memory  
    static int nv = 0 ;          // required in total 

    p = malloc (nbytes) ;
    if (p == NULL) {
      fprintf (stderr, "No memory left for additional %d bytes\n", nbytes) ;
      fprintf (stderr, "%ld bytes reserved in %d calls \n", nb, nv) ;  
      exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}



/***************************************************************************/
/***************************** Keyword Section *****************************/
/***************************************************************************/

typedef struct s_keyword { // for the reserved words of C  
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = {     // define the keywords 
    "main",        MAIN,      // and their associated token  
    "int",         INTEGER,
    "puts",        PUTS,
    "printf",      PRINTF,
    "while",       WHILE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "inc",         INC,
    "dec",         DEC,
    "switch",      SWITCH,
    "case",        CASE,
    "default",     DEFAULT,
    "break",       BREAK,
    "&&",          AND,
    "||",          OR,
    "!",          NOT,
    "==",          EQ,
    "!=",          NE,
    "<=",          LE,
    ">=",          GE,
    "return",      RETURN,
    NULL,          0          // 0 to mark the end of the table
} ;

t_keyword *search_keyword (char *symbol_name)
{                       // Search symbol names in the keyword table
                        // and return a pointer to token register
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
                                   // strcmp(a, b) returns == 0 if a==b  
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************** Section for the Lexical Analyzer  ********************/
/***************************************************************************/

char *gen_code (char *name)   // copy the argument to an  
{                             // string in dynamic memory  
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
    int i ;
    int c ;
    int cc ;
    char expandable_ops [] =  "<=>|%&/+-*^" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do { 
        c = getchar () ; 
        if (c == '#') { // Ignore the lines starting with # (#define, #include)
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        }
        if (c == '/') { // character / can be the beginning of a comment. 
            cc = getchar () ; 
            if (cc != '/') { // If the following char is / is a comment, but.... 
                ungetc (cc, stdin) ; 
            } else { 
                c = getchar () ; // ... 
                if (c == '@') { // Lines starting with //@ are transcribed
                    do {
                        c = getchar();
                        if (c == EOF) break;
                        putchar(c);
                    } while (c != '\n');
                } else { // ==> comment, ignore the line 
                    while (c != '\n' && c != EOF) { 
                        c = getchar () ; 
                    } 
                } 
            } 
        } 
        if (c == '\n') 
            n_line++ ; 
    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ; 
        } // we should read until the next “, but, what if it is  missing? 
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;       
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
        temp_str [i++] = tolower (c) ; // ALL TO SMALL LETTERS
        c = getchar () ; 
    } 
    temp_str [i] = '\0' ; // End of string  
    ungetc (c, stdin) ; // return excess char  

    yylval.code = gen_code (temp_str) ; 
    symbol = search_keyword (yylval.code) ;
    if (symbol == NULL) { // is not reserved word -> iderntifrier  
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (c == '!') {
    cc = getchar();
    if (cc == '=') {
        yylval.code = gen_code("!=");
        return NE;
    }
    ungetc(cc, stdin);
    return NOT;
    }

    if (strchr (expandable_ops, c) != NULL) { // // look for c in expandable_ops
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // although it is not used   
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


void clear_local_vars()
{
    local_vars = NULL;
}

void add_scoped_var(char *original, char *translated)
{
    t_localvar *p = (t_localvar *) my_malloc(sizeof(t_localvar));
    p->original = gen_code(original);
    p->translated = gen_code(translated);
    p->next = local_vars;
    local_vars = p;
}

void add_local_var(char *name)
{
    sprintf(temp, "%s_%s", current_function, name);
    add_scoped_var(name, temp);
}

void add_param_var(char *name)
{
    add_scoped_var(name, name);
}

char *translated_name(char *name)
{
    t_localvar *p = local_vars;

    while (p != NULL) {
        if (strcmp(p->original, name) == 0) {
            return gen_code(p->translated);
        }
        p = p->next;
    }

    return gen_code(name);
}

int main ()
{
    yyparse () ;
}
