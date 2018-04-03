          /* All possibilities should have been exhausted.  */
          abort ();
        }
      
      if (!(*dt & RETROKF))
        {
          if (!opt.verbose)
            {
              /* #### Ugly ugly ugly! */
              char *hurl = url_string (u, true);
              logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
              xfree (hurl);
            }
          logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
                     tms, hstat.statcode, escnonprint (hstat.error));
          logputs (LOG_VERBOSE, "\n");
          ret = WRONGCODE;
          goto exit;
        }

