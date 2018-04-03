          strcpy (tmp, "        ");
          if (count > 1)
            sprintf (tmp, _("(try:%2d)"), count);
          logprintf (LOG_VERBOSE, "--%s--  %s\n  %s => `%s'\n",
                     tms, hurl, tmp, locf);
#ifdef WINDOWS
          ws_changetitle (hurl);
#endif
