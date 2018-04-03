    }

  print_row_stats (dp, dltime, true);
  logputs (LOG_VERBOSE, "\n\n");
  log_set_flush (false);

  xfree (dp);
