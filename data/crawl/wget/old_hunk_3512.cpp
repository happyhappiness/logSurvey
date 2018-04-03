			dp->total_length);
    }

  print_download_speed (dp, dp->dots * dot_bytes
			+ dp->accumulated
			- dp->initial_length % row_bytes,
			dltime);
  logputs (LOG_VERBOSE, "\n\n");

  log_set_flush (0);

  xfree (dp);
