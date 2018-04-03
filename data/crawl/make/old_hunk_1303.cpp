      if (filenames != 0)						      \
	record_files (filenames, pattern, pattern_percent, deps,	      \
		      cmds_started, commands, commands_idx,		      \
		      two_colon, filename, lineno,			      \
		      !(flags & RM_NO_DEFAULT_GOAL));		     	      \
      filenames = 0;							      \
      commands_idx = 0;							      \
      if (pattern) { free(pattern); pattern = 0; }                            \
    } while (0)

  pattern_percent = 0;
  cmds_started = lineno;

  if (debug_flag)
    {
      printf ("Reading makefile `%s'", filename);
      if (flags & RM_NO_DEFAULT_GOAL)
	printf (" (no default goal)");
      if (flags & RM_INCLUDED)
