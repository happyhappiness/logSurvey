              hurl = url_string (u, true);
              logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
            }
          if (opt.spider && opt.recursive)
            {
              if (!hurl) hurl = url_string (u, true);
              nonexisting_url (hurl, referer);
            }
          logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
                     tms, hstat.statcode, escnonprint (hstat.error));
          logputs (LOG_VERBOSE, "\n");
          ret = WRONGCODE;
          xfree_null (hurl);
