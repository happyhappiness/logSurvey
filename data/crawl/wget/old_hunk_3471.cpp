void
logputs (enum log_options o, const char *s)
{
  CHECK_VERBOSE (o);
  CANONICALIZE_LOGFP_OR_RETURN;

  fputs (s, logfp);
  if (save_log_p)
    saved_append (s);

  if (flush_log_p)
    logflush ();
  else
