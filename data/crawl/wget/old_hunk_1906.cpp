  logfp = unique_create (DEFAULT_LOGFILE, false, &logfile);
  if (logfp)
    {
      fprintf (stderr, _("\n%s received, redirecting output to `%s'.\n"),
               redirect_request_signal_name, logfile);
      xfree (logfile);
      /* Dump the context output to the newly opened log.  */
      log_dump_context ();
