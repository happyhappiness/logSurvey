      url = url_parse (url_text, &up_error_code);
      if (!url)
        {
          char *error = url_error (url_text, up_error_code);
          logprintf (LOG_NOTQUIET, _("%s: Invalid URL %s: %s\n"),
                     file, url_text, error);
          xfree (url_text);
          xfree (error);
          continue;
        }
      xfree (url_text);
