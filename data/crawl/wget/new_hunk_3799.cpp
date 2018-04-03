{
  struct file_memory *fm;
  FILE               *fp;
  const char         *p;
  downloaded_file_t  downloaded_file_return;

  logprintf (LOG_VERBOSE, _("Converting %s... "), file);
