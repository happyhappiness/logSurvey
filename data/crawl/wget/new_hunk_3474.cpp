static void
display_image (char *buf)
{
  int old = log_set_save_context (0);
  logputs (LOG_VERBOSE, "\r");
  logputs (LOG_VERBOSE, buf);
  log_set_save_context (old);
}

static void
