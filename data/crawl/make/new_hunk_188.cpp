  if (save_stdin >= 0)
    {
      if (dup2 (save_stdin, FD_STDIN) != FD_STDIN)
        O (fatal, NILF, _("Could not restore stdin\n"));
      else
        close (save_stdin);
    }
