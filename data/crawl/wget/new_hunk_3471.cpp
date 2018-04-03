void
logputs (enum log_options o, const char *s)
{
  FILE *fp;

  check_redirect_output ();
  if (!(fp = get_log_fp ()))
    return;

  fputs (s, fp);
  if (save_context_p)
    saved_append (s);
  if (flush_log_p)
    logflush ();
  else
