static void
display_image (char *buf)
{
  char *del_buf = alloca (screen_width + 1);
  memset (del_buf, '\b', screen_width);
  del_buf[screen_width] = '\0';
  logputs (LOG_VERBOSE, del_buf);
  logputs (LOG_VERBOSE, buf);
}

static void
