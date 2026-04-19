(defun main ()
  (setq a 0)
  (loop while (< a 5) do
    (progn
      (if (= (mod a 2) 0)
          (princ a)
          (princ 0))
      (setf a (+ a 1))
    )
  )
)