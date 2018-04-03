      if (opt.verbose)
        {
          char *hurl = url_string (u, true);
          char tmp[256];
          strcpy (tmp, "        ");
          if (count > 1)
            sprintf (tmp, _("(try:%2d)"), count);
          logprintf (LOG_VERBOSE, "--%s--  %s\n  %s\n",
                     tms, hurl, tmp);
#ifdef WINDOWS
          ws_changetitle (hurl);
#endif
