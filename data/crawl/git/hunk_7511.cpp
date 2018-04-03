              (append (git-get-env-strings env) (list "git") args))
     (apply #'call-process "git" nil buffer nil args)))
 
+(defun git-call-process-display-error (&rest args)
+  "Wrapper for call-process that displays error messages."
+  (let* ((dir default-directory)
+         (buffer (get-buffer-create "*Git Command Output*"))
+         (ok (with-current-buffer buffer
+               (let ((default-directory dir)
+                     (buffer-read-only nil))
+                 (erase-buffer)
+                 (eq 0 (apply 'call-process "git" nil (list buffer t) nil args))))))
+    (unless ok (display-message-or-buffer buffer))
+    ok))
+
 (defun git-call-process-env-string (env &rest args)
   "Wrapper for call-process that sets environment strings,
 and returns the process output as a string."
