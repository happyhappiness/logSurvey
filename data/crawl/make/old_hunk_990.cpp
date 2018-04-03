  pattern_percent = 0;
  cmds_started = fileinfo.lineno;

  if (debug_flag)
    {
      printf (_("Reading makefile `%s'"), fileinfo.filenm);
      if (flags & RM_NO_DEFAULT_GOAL)
