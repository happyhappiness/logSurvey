
/* When SIGHUP or SIGUSR1 are received, the output is redirected
   elsewhere.  Such redirection is only allowed once. */
static enum { RR_NONE, RR_REQUESTED, RR_DONE } redirect_request = RR_NONE;
static const char *redirect_request_signal_name;

/* Redirect output to `wget-log'.  */

static void
redirect_output (void)
{
  char *logfile;
  logfp = unique_create (DEFAULT_LOGFILE, false, &logfile);
  if (logfp)
    {
      fprintf (stderr, _("\n%s received, redirecting output to %s.\n"),
               redirect_request_signal_name, quote (logfile));
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
               (logfile) ? logfile : DEFAULT_LOGFILE, strerror (errno));
      inhibit_logging = true;
    }
  save_context_p = false;
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
