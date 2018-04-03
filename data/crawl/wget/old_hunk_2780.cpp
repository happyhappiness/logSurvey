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

