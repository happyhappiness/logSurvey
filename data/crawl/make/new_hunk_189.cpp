  if (save_stdout >= 0)
    {
      if (dup2 (save_stdout, FD_STDOUT) != FD_STDOUT)
        O (fatal, NILF, _("Could not restore stdout\n"));
      else
        close (save_stdout);
    }
