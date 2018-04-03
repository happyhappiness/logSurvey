static void
memfatal (const char *what)
{
  /* Make sure we don't try to store part of the log line, and thus
     call malloc.  */
  log_set_save_context (0);
  logprintf (LOG_ALWAYS, _("%s: %s: Not enough memory.\n"), exec_name, what);
  exit (1);
}
