 
 #else /* !VMS */
 
-#if !defined (_AMIGA) && !defined (__MSDOS__)
+/* EMX: Start a child process. This function returns the new pid.  */
+# if defined __MSDOS__ ||  defined __EMX__
+int
+child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
+{
+  int pid;
+  /* stdin_fd == 0 means: nothing to do for stdin;
+     stdout_fd == 1 means: nothing to do for stdout */
+  int save_stdin = (stdin_fd != 0) ? dup (0) : 0;
+  int save_stdout = (stdout_fd != 1) ? dup (1): 1;
+
+  /* < 0 only if dup() failed */
+  if (save_stdin < 0)
+    fatal (NILF, _("could not duplicate stdin\n"));
+  if (save_stdout < 0)
+    fatal (NILF, _("could not duplicate stdout\n"));
+
+  /* Close unnecessary file handles for the child.  */
+  if (save_stdin != 0)
+    CLOSE_ON_EXEC (save_stdin);
+  if (save_stdout != 1)
+    CLOSE_ON_EXEC (save_stdout);
+
+  /* Connect the pipes to the child process.  */
+  if (stdin_fd != 0)
+    (void) dup2 (stdin_fd, 0);
+  if (stdout_fd != 1)
+    (void) dup2 (stdout_fd, 1);
+
+  /* stdin_fd and stdout_fd must be closed on exit because we are
+     still in the parent process */
+  if (stdin_fd != 0)
+    CLOSE_ON_EXEC (stdin_fd);
+  if (stdout_fd != 1)
+    CLOSE_ON_EXEC (stdout_fd);
+
+  /* Run the command.  */
+  pid = exec_command (argv, envp);
+
+  /* Restore stdout/stdin of the parent process.  */
+  if (stdin_fd != 0 && dup2 (save_stdin, 0) != 0)
+    fatal (NILF, _("restoring of stdin failed\n"));
+  if (stdout_fd != 1 && dup2 (save_stdout, 1) != 1)
+    fatal (NILF, _("restoring of stdout failed\n"));
+
+  return pid;
+}
+
+#elif !defined (_AMIGA) && !defined (__MSDOS__)
+
 /* UNIX:
    Replace the current process with one executing the command in ARGV.
    STDIN_FD and STDOUT_FD are used as the process's stdin and stdout; ENVP is
    the environment of the new program.  This function does not return.  */
-
 void
 child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
 {
