    (and (eq 0 (apply #' git-call-process-env t env args))
         (buffer-string))))

(defun git-call-process-string-display-error (&rest args)
  "Wrapper for call-process that displays error message and returns
the process output as a string, or nil if the git command failed."
  (with-temp-buffer
    (if (eq 0 (apply #'git-call-process-env (list t t) nil args))
        (buffer-string)
      (display-message-or-buffer (current-buffer))
      nil)))

(defun git-run-process-region (buffer start end program args)
  "Run a git process with a buffer region as input."
  (let ((output-buffer (current-buffer))
