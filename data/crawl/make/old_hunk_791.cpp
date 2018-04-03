  /* Run the command.  */
  pid = exec_command (argv, envp);

  /* Restore stdout/stdin of the parent process.  */
  if (stdin_fd != 0 && dup2 (save_stdin, 0) != 0)
    fatal (NILF, _("restoring of stdin failed\n"));
  if (stdout_fd != 1 && dup2 (save_stdout, 1) != 1)
    fatal (NILF, _("restoring of stdout failed\n"));

  return pid;
}
