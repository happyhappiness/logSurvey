         {
           save_stderr = dup (FD_STDERR);
           if (save_stderr < 0)
-            fatal (NILF, _("no more file handles: could not duplicate stderr\n"));
+            O (fatal, NILF,
+               _("no more file handles: could not duplicate stderr\n"));
           CLOSE_ON_EXEC (save_stderr);
         }
 