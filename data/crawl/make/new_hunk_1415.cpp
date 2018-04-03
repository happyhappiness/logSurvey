
      time_t *makefile_mtimes = 0;
      unsigned int mm_idx = 0;
      char **nargv = argv;
      char nargc = argc;

      if (debug_flag)
	puts ("Updating makefiles....");
