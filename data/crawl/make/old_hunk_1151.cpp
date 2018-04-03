
  if (debug_flag)
    {
      printf ("Reading makefile `%s'", fileinfo.filenm);
      if (flags & RM_NO_DEFAULT_GOAL)
	printf (" (no default goal)");
      if (flags & RM_INCLUDED)
	printf (" (search path)");
      if (flags & RM_DONTCARE)
	printf (" (don't care)");
      if (flags & RM_NO_TILDE)
	printf (" (no ~ expansion)");
      puts ("...");
    }

