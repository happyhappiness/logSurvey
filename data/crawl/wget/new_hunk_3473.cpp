      fputs (log_lines[log_line_current].content, fp);
  fflush (fp);
}

/* When SIGHUP or SIGUSR1 are received, the output is redirected
   elsewhere.  Such redirection is only allowed once. */
enum { RR_NONE, RR_REQUESTED, RR_DONE } redirect_request = RR_NONE;
static const char *redirect_request_signal_name;

/* Redirect output to `wget-log'.  */

static void
redirect_output (void)
{
  char *logfile = unique_name (DEFAULT_LOGFILE);
  fprintf (stderr, _("\n%s received, redirecting output to `%s'.\n"),
	   redirect_request_signal_name, logfile);
  logfp = fopen (logfile, "w");
  if (!logfp)
    {
      /* Eek!  Opening the alternate log file has failed.  Nothing we
         can do but disable printing completely. */
      fprintf (stderr, _("%s: %s; disabling logging.\n"),
	       logfile, strerror (errno));
      inhibit_logging = 1;
    }
  else
    {
      /* Dump the context output to the newly opened log.  */
      log_dump_context ();
    }
  xfree (logfile);
  save_context_p = 0;
}

/* Check whether a signal handler requested the output to be
   redirected. */

static void
check_redirect_output (void)
{
  if (redirect_request == RR_REQUESTED)
    {
      redirect_request = RR_DONE;
      redirect_output ();
    }
}

/* Request redirection at a convenient time.  This may be called from
   a signal handler. */

void
log_request_redirect_output (const char *signal_name)
{
  if (redirect_request == RR_NONE && save_context_p)
    /* Request output redirection.  The request will be processed by
       check_redirect_output(), which is called from entry point log
       functions. */
    redirect_request = RR_REQUESTED;
  redirect_request_signal_name = signal_name;
}
