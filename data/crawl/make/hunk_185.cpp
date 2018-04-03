     {
       save_stdin = dup (FD_STDIN);
       if (save_stdin < 0)
-        fatal (NILF, _("no more file handles: could not duplicate stdin\n"));
+        O (fatal, NILF, _("no more file handles: could not duplicate stdin\n"));
       CLOSE_ON_EXEC (save_stdin);
 
       dup2 (stdin_fd, FD_STDIN);
