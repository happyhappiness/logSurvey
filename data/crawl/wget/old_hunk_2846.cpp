redirect_output (void)
{
  char *logfile;
  logfp = unique_create (DEFAULT_LOGFILE, 0, &logfile);
  if (logfp)
    {
      fprintf (stderr, _("\n%s received, redirecting output to `%s'.\n"),
