static void
redirect_output (void)
{
  char *logfile;
  logfp = unique_create (DEFAULT_LOGFILE, 0, &logfile);
  if (logfp)
    {
      fprintf (stderr, _("\n%s received, redirecting output to `%s'.\n"),
	       redirect_request_signal_name, logfile);
      xfree (logfile);
      /* Dump the context output to the newly opened log.  */
      log_dump_context ();
    }
  else
    {
      /* Eek!  Opening the alternate log file has failed.  Nothing we
         can do but disable printing completely. */
      fprintf (stderr, _("\n%s received.\n"), redirect_request_signal_name);
      fprintf (stderr, _("%s: %s; disabling logging.\n"),
	       logfile, strerror (errno));
      inhibit_logging = 1;
    }
  save_context_p = 0;
}

