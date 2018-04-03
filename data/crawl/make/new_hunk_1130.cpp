      int nargc = argc;

      if (debug_flag)
	puts (_("Updating makefiles...."));

      /* Remove any makefiles we don't want to try to update.
	 Also record the current modtimes so we can compare them later.  */
