              }

          if (!www_authenticate)
            /* If the authentication header is missing or
               unrecognized, there's no sense in retrying.  */
            logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
          else if (BEGINS_WITH (www_authenticate, "Basic"))
            /* If the authentication scheme is "Basic", which we send
               by default, there's no sense in retrying either.  (This
               should be changed when we stop sending "Basic" data by
               default.)  */
            ;
          else
            {
              char *pth;
              pth = url_full_path (u);
