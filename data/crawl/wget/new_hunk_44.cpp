
/* When SIGHUP or SIGUSR1 are received, the output is redirected
   elsewhere.  Such redirection is only allowed once. */
static const char *redirect_request_signal_name;

/* Redirect output to `wget-log' or back to stdout/stderr.  */

void
redirect_output (bool to_file, const char *signal_name)
{
  if (to_file && logfp != filelogfp)
    {
      if (signal_name)
        {
          fprintf (stderr, "\n%s received.", signal_name);
        }
      if (!filelogfp)
        {
          filelogfp = unique_create (DEFAULT_LOGFILE, false, &logfile);
          if (filelogfp)
            {
              fprintf (stderr, _("\nRedirecting output to %s.\n"),
                  quote (logfile));
              /* Store signal name to tell wget it's permanent redirect to log file */
              redirect_request_signal_name = signal_name;
              logfp = filelogfp;
              /* Dump the context output to the newly opened log.  */
              log_dump_context ();
            }
          else
            {
              /* Eek!  Opening the alternate log file has failed.  Nothing we
                can do but disable printing completely. */
              fprintf (stderr, _("%s: %s; disabling logging.\n"),
                      (logfile) ? logfile : DEFAULT_LOGFILE, strerror (errno));
              inhibit_logging = true;
            }
        }
      else
        {
          fprintf (stderr, _("\nRedirecting output to %s.\n"),
              quote (logfile));
          logfp = filelogfp;
          log_dump_context ();
        }
    }
  else if (!to_file && logfp != stdlogfp)
    {
      logfp = stdlogfp;
      log_dump_context ();
    }
}

/* Check whether there's a need to redirect output. */

static void
check_redirect_output (void)
{
#ifndef WINDOWS
  /* If it was redirected already to log file by SIGHUP or SIGUSR1,
   * it was permanent and since that redirect_request_signal_name is set.
   * If there was no SIGHUP or SIGUSR1 and shell is interactive
   * we check if process is fg or bg before every line is printed.*/
  if (!redirect_request_signal_name && shell_is_interactive)
    {
      if (tcgetpgrp (STDIN_FILENO) != getpgrp ())
        {
          // Process backgrounded
          redirect_output (true,NULL);
        }
      else
        {
          // Process foregrounded
          redirect_output (false,NULL);
        }
    }
#endif /* WINDOWS */
}
