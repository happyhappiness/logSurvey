    {
      /* When done, print the total download time */
      if (dltime >= 10)
        logprintf (LOG_PROGRESS, "=%s",
                   eta_to_human_short ((int) (dltime + 0.5), true));
      else
        logprintf (LOG_PROGRESS, "=%ss", print_decimal (dltime));
    }
}

