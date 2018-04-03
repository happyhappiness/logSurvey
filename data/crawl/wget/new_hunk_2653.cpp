          /* All possibilities should have been exhausted.  */
          abort ();
        }
     
      if (!(*dt & RETROKF))
        {
          char *hurl = NULL;
          if (!opt.verbose)
            {
              /* #### Ugly ugly ugly! */
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
          goto exit;
        }

