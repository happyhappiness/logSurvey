               * give up. */
            }
        }
      logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
      request_free (req);
      xfree_null (message);
      resp_free (resp);
      xfree (head);
      return AUTHFAILED;
    }
  else /* statcode != HTTP_STATUS_UNAUTHORIZED */
    {
