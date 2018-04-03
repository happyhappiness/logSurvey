    {
      save_stdout = dup (FD_STDOUT);
      if (save_stdout < 0)
        O (fatal, NILF,
           _("no more file handles: could not duplicate stdout\n"));
      CLOSE_ON_EXEC (save_stdout);

      dup2 (stdout_fd, FD_STDOUT);
