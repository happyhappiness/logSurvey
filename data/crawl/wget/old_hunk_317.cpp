logputs (enum log_options o, const char *s)
{
  FILE *fp;

  check_redirect_output ();
  if ((fp = get_log_fp ()) == NULL)
    return;
  CHECK_VERBOSE (o);

  FPUTS (s, fp);
  if (save_context_p)
    saved_append (s);
  if (flush_log_p)
