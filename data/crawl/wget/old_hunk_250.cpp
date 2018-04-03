      if (!opt.server_response && err != FTPSRVERR)
        logputs (LOG_VERBOSE, _("done.    "));

      /* Fourth: Find the initial ftp directory */

      if (!opt.server_response)
