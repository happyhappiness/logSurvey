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
              char *pth;
              pth = url_full_path (u);
