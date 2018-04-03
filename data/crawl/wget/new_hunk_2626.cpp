      /* Did we get the time-stamp? */
      if (!got_head)
        {
          bool restart_loop = false;

          if (opt.timestamping && !hstat.remote_time)
            {
              logputs (LOG_NOTQUIET, _("\
