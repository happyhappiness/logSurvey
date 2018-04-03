  else if (pid != 0)
    {
      /* parent, no error */
      printf (_("Continuing in background, pid %d.\n"), (int)pid);
      if (logfile_changed)
	printf (_("Output will be written to `%s'.\n"), opt.lfilename);
      exit (0);			/* #### should we use _exit()? */
