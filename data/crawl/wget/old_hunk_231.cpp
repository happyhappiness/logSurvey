    }

  print_row_stats (dp, dltime, true);
  logputs (LOG_PROGRESS, "\n\n");
  log_set_flush (false);

  xfree (dp);
