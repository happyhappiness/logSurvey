      logfp = stdin;
    }
  fprintf (stderr, messij, logfile);
  xfree (logfile);
  /* Dump the previous screenful of output to LOGFILE.  */
  log_dump ();
  save_log_p = 0;
