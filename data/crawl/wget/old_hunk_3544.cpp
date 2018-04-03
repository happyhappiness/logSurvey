			dp->total_length);
    }

  print_elapsed (dp, dp->dots * dot_bytes
		 + dp->accumulated
		 - dp->initial_length % row_bytes);
  logputs (LOG_VERBOSE, "\n\n");

  log_set_flush (0);
