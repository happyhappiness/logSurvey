  unsigned int num_makefiles = 0;

  if (debug_flag)
    puts (_("Reading makefiles..."));

  /* If there's a non-null variable MAKEFILES, its value is a list of
     files to read first thing.  But don't let it prevent reading the
