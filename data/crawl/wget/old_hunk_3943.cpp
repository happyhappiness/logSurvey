      logfp = stdin;
    }
  fprintf (stderr, messij, logfile);
  free (logfile);
  /* Dump the previous screenful of output to LOGFILE.  */
  log_dump ();
  save_log_p = 0;
