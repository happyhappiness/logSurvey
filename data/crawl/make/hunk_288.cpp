 /* EMX: Start a child process. This function returns the new pid.  */
 # if defined __EMX__
 int
-child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
+child_execute_job (int stdin_fd, int stdout_fd, int stderr_fd,
+                   char **argv, char **envp)
 {
   int pid;
-  /* stdin_fd == 0 means: nothing to do for stdin;
-     stdout_fd == 1 means: nothing to do for stdout */
-  int save_stdin = (stdin_fd != 0) ? dup (0) : 0;
-  int save_stdout = (stdout_fd != 1) ? dup (1): 1;
-
-  /* < 0 only if dup() failed */
-  if (save_stdin < 0)
-    fatal (NILF, _("no more file handles: could not duplicate stdin\n"));
-  if (save_stdout < 0)
-    fatal (NILF, _("no more file handles: could not duplicate stdout\n"));
-
-  /* Close unnecessary file handles for the child.  */
-  if (save_stdin != 0)
-    CLOSE_ON_EXEC (save_stdin);
-  if (save_stdout != 1)
-    CLOSE_ON_EXEC (save_stdout);
-
-  /* Connect the pipes to the child process.  */
-  if (stdin_fd != 0)
-    (void) dup2 (stdin_fd, 0);
-  if (stdout_fd != 1)
-    (void) dup2 (stdout_fd, 1);
-
-  /* stdin_fd and stdout_fd must be closed on exit because we are
-     still in the parent process */
-  if (stdin_fd != 0)
-    CLOSE_ON_EXEC (stdin_fd);
-  if (stdout_fd != 1)
-    CLOSE_ON_EXEC (stdout_fd);
+  int save_stdin = -1;
+  int save_stdout = -1;
+  int save_stderr = -1;
+
+  /* For each FD which needs to be redirected first make a dup of the standard
+     FD to save and mark it close on exec so our child won't see it.  Then
+     dup2() the standard FD to the redirect FD, and also mark the redirect FD
+     as close on exec. */
+  if (stdin_fd != FD_STDIN)
+    {
+      save_stdin = dup (FD_STDIN);
+      if (save_stdin < 0)
+        fatal (NILF, _("no more file handles: could not duplicate stdin\n"));
+      CLOSE_ON_EXEC (save_stdin);
+
+      dup2 (stdin_fd, FD_STDIN);
+      CLOSE_ON_EXEC (stdin_fd);
+    }
+
+  if (stdout_fd != FD_STDOUT)
+    {
+      save_stdout = dup (FD_STDOUT);
+      if (save_stdout < 0)
+        fatal (NILF, _("no more file handles: could not duplicate stdout\n"));
+      CLOSE_ON_EXEC (save_stdout);
+
+      dup2 (stdout_fd, FD_STDOUT);
+      CLOSE_ON_EXEC (stdout_fd);
+    }
+
+  if (stderr_fd != FD_STDERR)
+    {
+      if (stderr_fd != stdout_fd)
+        {
+          save_stderr = dup (FD_STDERR);
+          if (save_stderr < 0)
+            fatal (NILF, _("no more file handles: could not duplicate stderr\n"));
+          CLOSE_ON_EXEC (save_stderr);
+        }
+
+      dup2 (stderr_fd, FD_STDERR);
+      CLOSE_ON_EXEC (stderr_fd);
+    }
 
   /* Run the command.  */
   pid = exec_command (argv, envp);
 
-  /* Restore stdout/stdin of the parent and close temporary FDs.  */
-  if (stdin_fd != 0)
+  /* Restore stdout/stdin/stderr of the parent and close temporary FDs.  */
+  if (save_stdin >= 0)
     {
-      if (dup2 (save_stdin, 0) != 0)
+      if (dup2 (save_stdin, FD_STDIN) != 0)
         fatal (NILF, _("Could not restore stdin\n"));
       else
         close (save_stdin);
     }
 
-  if (stdout_fd != 1)
+  if (save_stdout >= 0)
     {
-      if (dup2 (save_stdout, 1) != 1)
+      if (dup2 (save_stdout, FD_STDOUT) != 0)
         fatal (NILF, _("Could not restore stdout\n"));
       else
         close (save_stdout);
     }
 
+  if (save_stderr >= 0)
+    {
+      if (dup2 (save_stderr, FD_STDERR) != 0)
+        fatal (NILF, _("Could not restore stderr\n"));
+      else
+        close (save_stderr);
+    }
+
   return pid;
 }
 
