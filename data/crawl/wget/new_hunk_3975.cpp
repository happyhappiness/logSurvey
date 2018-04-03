  fputs (s, logfp);
  if (!opt.no_flush)
    fflush (logfp);
  if (save_log_p)
    saved_append (s);
}

/* Print a message to the log.  A copy of message will be saved to
   saved_log, for later reusal by log_dump().  */

static void
logvprintf (enum log_options o, const char *fmt, va_list args)
{
