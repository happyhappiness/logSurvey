              hurl = url_string (u, true);
              logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
            }
          /* Maybe we should always keep track of broken links, not just in
           * spider mode.  */
          if (opt.spider)
            {
              /* #### Again: ugly ugly ugly! */
              if (!hurl) 
                hurl = url_string (u, true);
              nonexisting_url (hurl);
              logprintf (LOG_NOTQUIET, _("\
Remote file does not exist -- broken link!!!\n"));
            }
          else
            {
              logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
                         tms, hstat.statcode, escnonprint (hstat.error));
            }
          logputs (LOG_VERBOSE, "\n");
          ret = WRONGCODE;
          xfree_null (hurl);
