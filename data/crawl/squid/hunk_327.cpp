         if (kill(pid, opt_send_signal) &&
                 /* ignore permissions if just running check */
                 !(opt_send_signal == 0 && errno == EPERM)) {
+            int xerrno = errno;
             fprintf(stderr, "%s: ERROR: Could not send ", APP_SHORTNAME);
             fprintf(stderr, "signal %d to process %d: %s\n",
-                    opt_send_signal, (int) pid, xstrerror());
+                    opt_send_signal, (int) pid, xstrerr(xerrno));
             exit(1);
         }
     } else {
