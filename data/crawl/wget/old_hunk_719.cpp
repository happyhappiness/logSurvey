        }
      else
        {
          int dt = 0;
          char *redirected = NULL;

          status = retrieve_url (url, &file, &redirected, referer, &dt, false);

          if (html_allowed && file && status == RETROK
              && (dt & RETROKF) && (dt & TEXTHTML))
