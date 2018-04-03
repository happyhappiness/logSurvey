    {
      const char *txt_addr = print_address (ip);
      if (0 != strcmp (print, txt_addr))
        logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
                   escnonprint_uri (print), txt_addr, port);
      else
        logprintf (LOG_VERBOSE, _("Connecting to %s:%d... "), txt_addr, port);
    }
