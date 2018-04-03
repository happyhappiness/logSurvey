                                  rel_value);
              if (BEGINS_WITH (www_authenticate, "NTLM"))
                ntlm_seen = true;
              else if (!u->user && BEGINS_WITH (www_authenticate, "Basic"))
                {
                  /* Need to register this host as using basic auth,
                   * so we automatically send creds next time. */
                  register_basic_auth_host (u->host);
                }
              xfree (pth);
              goto retry_with_auth;
            }
          else
            {
              /* We already did Basic auth, and it failed. Gotta
               * give up. */
            }
        }
      logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
      request_free (req);
