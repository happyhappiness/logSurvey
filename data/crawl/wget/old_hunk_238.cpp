    {
      /* When done, print the total download time */
      if (dltime >= 10)
        logprintf (LOG_VERBOSE, "=%s",
                   eta_to_human_short ((int) (dltime + 0.5), true));
      else
        logprintf (LOG_VERBOSE, "=%ss", print_decimal (dltime));
    }
}

