        }
      /* End of time-stamping section. */

      if (opt.spider)
        {
          logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
                     escnonprint (hstat.error));
