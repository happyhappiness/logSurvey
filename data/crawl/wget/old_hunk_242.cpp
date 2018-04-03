display_image (char *buf)
{
  bool old = log_set_save_context (false);
  logputs (LOG_VERBOSE, "\r");
  logputs (LOG_VERBOSE, buf);
  log_set_save_context (old);
}

