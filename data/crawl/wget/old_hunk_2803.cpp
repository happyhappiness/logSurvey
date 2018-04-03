      assert (dp->dots < opt.dots_in_line);

      dp->accumulated = remainder;
      dp->rows = skipped / row_bytes;
    }

  return dp;
}

static void
print_percentage (wgint bytes, wgint expected)
{
  /* Round to the floor value in order to gauge how much data *has*
     been retrieved.  12.8% will round to 12% because the 13% mark has
     not yet been reached.  100% is only shown when done.  */
  int percentage = 100.0 * bytes / expected;
  logprintf (LOG_VERBOSE, "%3d%%", percentage);
}

static void
print_download_speed (struct dot_progress *dp, wgint bytes, double dltime)
{
  logprintf (LOG_VERBOSE, " %7s",
	     retr_rate (bytes, dltime - dp->last_timer_value));
  dp->last_timer_value = dltime;
}

/* Dot-progress backend for progress_update. */
