
  if (dp->dots == 0)
    logprintf (LOG_VERBOSE, "\n%6sK",
	       number_to_static_string (dp->rows * ROW_BYTES / 1024));
  for (i = dp->dots; i < opt.dots_in_line; i++)
    {
      if (i % opt.dot_spacing == 0)
	logputs (LOG_VERBOSE, " ");
      logputs (LOG_VERBOSE, " ");
    }

