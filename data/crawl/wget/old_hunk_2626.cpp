      /* Did we get the time-stamp? */
      if (!got_head)
        {
          if (opt.timestamping && !hstat.remote_time)
            {
              logputs (LOG_NOTQUIET, _("\
