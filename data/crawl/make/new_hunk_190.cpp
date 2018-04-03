  if (save_stderr >= 0)
    {
      if (dup2 (save_stderr, FD_STDERR) != FD_STDERR)
        O (fatal, NILF, _("Could not restore stderr\n"));
      else
        close (save_stderr);
    }
