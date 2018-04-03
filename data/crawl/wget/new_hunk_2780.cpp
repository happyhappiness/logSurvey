	  wgint bytes_remaining = dp->total_length - bytes_displayed;
	  /* The quantity downloaded in this download run. */
	  wgint bytes_sofar = bytes_displayed - dp->initial_length;
	  int eta = (int) (dltime * bytes_remaining / bytes_sofar + 0.5);
	  logprintf (LOG_VERBOSE, " %s", eta_to_human_short (eta, true));
	}
    }
  else
    {
      /* When done, print the total download time */
      if (dltime >= 10)
	logprintf (LOG_VERBOSE, "=%s",
		   eta_to_human_short ((int) (dltime + 0.5), true));
      else
	logprintf (LOG_VERBOSE, "=%ss", print_decimal (dltime));
    }
}
