             (append (git-get-env-strings env) (list "git") args))
    (apply #'call-process "git" nil buffer nil args)))

(defun git-call-process-env-string (env &rest args)
  "Wrapper for call-process that sets environment strings,
and returns the process output as a string."
