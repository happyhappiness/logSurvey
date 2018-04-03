void
log_close (void)
{
  fclose (logfp);
  save_log_p = 0;
  FREE_MAYBE (saved_log);
  saved_log = NULL;
  saved_log_size = saved_log_offset = 0;
}

/* Dump SAVED_LOG using logprintf(), but quit further logging to memory.
   Also, free the memory occupied by saved_log.  */
static void
log_dump (void)
{
  save_log_p = 0;
  if (!saved_log)
    return;
  logputs (LOG_ALWAYS, saved_log);
  free (saved_log);
  saved_log = NULL;
  saved_log_size = saved_log_offset = 0;
}

/* Redirect output to `wget-log' if opt.lfile is stdout.  MESSIJ is
   printed on stdout, and should contain *exactly one* `%s', which
   will be replaced by the log file name.

   If logging was not enabled, MESSIJ will not be printed.  */
void
