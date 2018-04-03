logputs (enum log_options o, const char *s)
{
  FILE *fp;
  FILE *warcfp;

  check_redirect_output ();
  if ((fp = get_log_fp ()) == NULL)
    return;
  warcfp = get_warc_log_fp ();
  CHECK_VERBOSE (o);

  FPUTS (s, fp);
  if (warcfp != NULL)
    FPUTS (s, warcfp);
  if (save_context_p)
    saved_append (s);
  if (flush_log_p)
