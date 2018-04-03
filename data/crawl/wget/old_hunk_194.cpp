             the value "negotiate", and other(s) with data.  Loop over
             all the occurrences and pick the one we recognize.  */
          int wapos;
          const char *wabeg, *waend;
          char *www_authenticate = NULL;
          for (wapos = 0;
               (wapos = resp_header_locate (resp, "WWW-Authenticate", wapos,
                                            &wabeg, &waend)) != -1;
               ++wapos)
            if (known_authentication_scheme_p (wabeg, waend))
              {
                BOUNDED_TO_ALLOCA (wabeg, waend, www_authenticate);
                break;
              }

          if (!www_authenticate)
            {
              /* If the authentication header is missing or
                 unrecognized, there's no sense in retrying.  */
              logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
            }
          else if (!basic_auth_finished
                   || !BEGINS_WITH (www_authenticate, "Basic"))
            {
              char *pth = url_full_path (u);
              const char *value;
