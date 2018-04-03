dot_finish (void *progress, double dltime)
{
  struct dot_progress *dp = progress;
  wgint ROW_BYTES = opt.dot_bytes * opt.dots_in_line;
  int i;

  log_set_flush (false);

  if (dp->dots == 0)
    logprintf (LOG_VERBOSE, "\n%6sK",
	       number_to_static_string (dp->rows * ROW_BYTES / 1024));
  for (i = dp->dots; i < opt.dots_in_line; i++)
    {
      if (i % opt.dot_spacing == 0)
	logputs (LOG_VERBOSE, " ");
      logputs (LOG_VERBOSE, " ");
    }

  print_row_stats (dp, dltime, true);
  logputs (LOG_VERBOSE, "\n\n");
  log_set_flush (false);

