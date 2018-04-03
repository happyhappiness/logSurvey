  fputs (s, logfp);
  if (!opt.no_flush)
    fflush (logfp);

  if (save_log_p && saved_log_size < SAVED_LOG_MAXSIZE)
    {
      int len = strlen (s);

      /* Increase size of SAVED_LOG exponentially.  */
      DO_REALLOC (saved_log, saved_log_size,
		  saved_log_offset + len + 1, char);
      memcpy (saved_log + saved_log_offset, s, len + 1);
      saved_log_offset += len;
    }
}

/* Print a message to the log file logfp.  If logfp is NULL, print to
   stderr.  If logfp is stdin, don't print at all.  A copy of message
   will be saved to saved_log, for later reusal by dump_log().  */
static void
logvprintf (enum log_options o, const char *fmt, va_list args)
{
