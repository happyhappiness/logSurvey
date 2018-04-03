
   The second reason why these are useful is that, if DEBUG_MALLOC is
   defined, they also provide a handy (if crude) malloc debugging
   interface that checks for memory leaks.  */

/* Croak the fatal memory error and bail out with non-zero exit
   status.  */

static void
memfatal (const char *context, long attempted_size)
{
  /* Make sure we don't try to store part of the log line, and thus
     call malloc.  */
  log_set_save_context (0);
  logprintf (LOG_ALWAYS,
	     _("%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"),
	     exec_name, context, attempted_size);
  exit (1);
}

