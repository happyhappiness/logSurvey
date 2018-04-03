          con->csock = -1;
        }
      if (!opt.spider)
        logprintf (LOG_VERBOSE, _("%s (%s) - %s saved [%s]\n\n"),
                   tms, tmrate, quote (locf), number_to_static_string (len));
      if (!opt.verbose && !opt.quiet)
        {
          /* Need to hide the password from the URL.  The `if' is here
