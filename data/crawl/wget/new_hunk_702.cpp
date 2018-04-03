        }
      else
        {
          int dt = 0, url_err;
          char *redirected = NULL;
          struct url *url_parsed = url_parse (url, &url_err);

          if (!url_parsed)
            {
              char *error = url_error (url, url_err);
              logprintf (LOG_NOTQUIET, "%s: %s.\n", url, error);
              xfree (error);
              status = URLERROR;
            }
          else
            {
              status = retrieve_url (url, &file, &redirected, referer, &dt, false);
            }

          if (html_allowed && file && status == RETROK
              && (dt & RETROKF) && (dt & TEXTHTML))
