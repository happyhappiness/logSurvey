      assert (dp->dots < opt.dots_in_line);

      dp->accumulated = remainder;
      dp->rows = skipped / ROW_BYTES;
    }

  return dp;
}

static const char *eta_to_human_short (int, bool);

/* Prints the stats (percentage of completion, speed, ETA) for current
   row.  DLTIME is the time spent downloading the data in current
   row.

   #### This function is somewhat uglified by the fact that current
   row and last row have somewhat different stats requirements.  It
   might be worthwhile to split it to two different functions.  */

static void
print_row_stats (struct dot_progress *dp, double dltime, bool last)
{
  const wgint ROW_BYTES = opt.dot_bytes * opt.dots_in_line;

  /* bytes_displayed is the number of bytes indicated to the user by
     dots printed so far, includes the initially "skipped" amount */
  wgint bytes_displayed = dp->rows * ROW_BYTES + dp->dots * opt.dot_bytes;

  if (last)
    /* For last row also count bytes accumulated after last dot */
    bytes_displayed += dp->accumulated;

  if (dp->total_length)
    {
      /* Round to floor value to provide gauge how much data *has*
	 been retrieved.  12.8% will round to 12% because the 13% mark
	 has not yet been reached.  100% is only shown when done.  */
      int percentage = 100.0 * bytes_displayed / dp->total_length;
      logprintf (LOG_VERBOSE, "%3d%%", percentage);
    }

  {
    static char names[] = {' ', 'K', 'M', 'G'};
    int units;
    double rate;
    wgint bytes_this_row;
    if (!last)
      bytes_this_row = ROW_BYTES;
    else
      /* For last row also include bytes accumulated after last dot.  */
      bytes_this_row = dp->dots * opt.dot_bytes + dp->accumulated;
    if (dp->rows == dp->initial_length / ROW_BYTES)
      /* Don't count the portion of the row belonging to initial_length */
      bytes_this_row -= dp->initial_length % ROW_BYTES;
    rate = calc_rate (bytes_this_row, dltime - dp->last_timer_value, &units);
    logprintf (LOG_VERBOSE, " %4.*f%c",
	       rate >= 100 ? 0 : rate >= 9.995 ? 1 : 2,
	       rate, names[units]);
    dp->last_timer_value = dltime;
  }

  if (!last)
    {
      if (dp->total_length)
	{
	  wgint bytes_remaining = dp->total_length - bytes_displayed;
	  /* The quantity downloaded in this download run. */
	  wgint bytes_sofar = bytes_displayed - dp->initial_length;
	  double secs_sofar = dltime / 1000;
	  int eta = (int) (secs_sofar * bytes_remaining / bytes_sofar + 0.5);
	  logprintf (LOG_VERBOSE, " %s", eta_to_human_short (eta, true));
	}
    }
  else
    {
      /* When done, print the total download time */
      double secs = dltime / 1000;
      if (secs >= 10)
	logprintf (LOG_VERBOSE, "=%s",
		   eta_to_human_short ((int) (secs + 0.5), true));
      else
	logprintf (LOG_VERBOSE, "=%ss", print_decimal (secs));
    }
}

/* Dot-progress backend for progress_update. */
