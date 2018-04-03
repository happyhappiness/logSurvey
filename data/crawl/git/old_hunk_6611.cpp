    (and (eq 0 (apply #' git-call-process-env t env args))
         (buffer-string))))

(defun git-run-process-region (buffer start end program args)
  "Run a git process with a buffer region as input."
  (let ((output-buffer (current-buffer))
