                                  rel_value);
              if (BEGINS_WITH (www_authenticate, "NTLM"))
                ntlm_seen = true;
              xfree (pth);
              goto retry_with_auth;
            }
        }
      logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
      request_free (req);
