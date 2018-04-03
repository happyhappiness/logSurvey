/* EMX: Start a child process. This function returns the new pid.  */
# if defined __EMX__
int
child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
{
  int pid;
  /* stdin_fd == 0 means: nothing to do for stdin;
     stdout_fd == 1 means: nothing to do for stdout */
  int save_stdin = (stdin_fd != 0) ? dup (0) : 0;
  int save_stdout = (stdout_fd != 1) ? dup (1): 1;

  /* < 0 only if dup() failed */
  if (save_stdin < 0)
    fatal (NILF, _("no more file handles: could not duplicate stdin\n"));
  if (save_stdout < 0)
    fatal (NILF, _("no more file handles: could not duplicate stdout\n"));

  /* Close unnecessary file handles for the child.  */
  if (save_stdin != 0)
    CLOSE_ON_EXEC (save_stdin);
  if (save_stdout != 1)
    CLOSE_ON_EXEC (save_stdout);

  /* Connect the pipes to the child process.  */
  if (stdin_fd != 0)
    (void) dup2 (stdin_fd, 0);
  if (stdout_fd != 1)
    (void) dup2 (stdout_fd, 1);

  /* stdin_fd and stdout_fd must be closed on exit because we are
     still in the parent process */
  if (stdin_fd != 0)
    CLOSE_ON_EXEC (stdin_fd);
  if (stdout_fd != 1)
    CLOSE_ON_EXEC (stdout_fd);

  /* Run the command.  */
  pid = exec_command (argv, envp);

  /* Restore stdout/stdin of the parent and close temporary FDs.  */
  if (stdin_fd != 0)
    {
      if (dup2 (save_stdin, 0) != 0)
        fatal (NILF, _("Could not restore stdin\n"));
      else
        close (save_stdin);
    }

  if (stdout_fd != 1)
    {
      if (dup2 (save_stdout, 1) != 1)
        fatal (NILF, _("Could not restore stdout\n"));
      else
        close (save_stdout);
    }

  return pid;
}

