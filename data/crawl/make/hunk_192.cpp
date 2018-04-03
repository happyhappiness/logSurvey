         execvp (shell, new_argv);
 # endif
         if (errno == ENOENT)
-          error (NILF, _("%s: Shell program not found"), shell);
+          OS (error, NILF, _("%s: Shell program not found"), shell);
         else
           perror_with_name ("execvp: ", shell);
         break;
