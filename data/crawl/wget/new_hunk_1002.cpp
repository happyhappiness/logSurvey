      newloc_parsed = url_parse (mynewloc, &up_error_code);
      if (!newloc_parsed)
        {
          char *error = url_error (mynewloc, up_error_code);
          logprintf (LOG_NOTQUIET, "%s: %s.\n", escnonprint_uri (mynewloc),
                     error);
          url_free (u);
          xfree (url);
          xfree (mynewloc);
          xfree (error);
          RESTORE_POST_DATA;
          return result;
        }
