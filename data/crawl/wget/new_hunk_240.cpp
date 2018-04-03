  log_set_flush (false);

  if (dp->dots == 0)
    logprintf (LOG_PROGRESS, "\n%6sK",
               number_to_static_string (dp->rows * ROW_BYTES / 1024));
  for (i = dp->dots; i < opt.dots_in_line; i++)
    {
      if (i % opt.dot_spacing == 0)
        logputs (LOG_PROGRESS, " ");
      logputs (LOG_PROGRESS, " ");
    }

  print_row_stats (dp, dltime, true);
  logputs (LOG_PROGRESS, "\n\n");
  log_set_flush (false);

  xfree (dp);
