      sleep_between_retrievals (count);
      
      /* Get the current time string.  */
      tms = datetime_str (time (NULL));
      
      if (opt.spider && !got_head)
        logprintf (LOG_VERBOSE, _("\
