        contlen = parsed;
    }

  /* Check for keep-alive related responses. */
  if (!inhibit_keep_alive && contlen != -1)
    {
      if (resp_header_copy (resp, "Keep-Alive", NULL, 0))
        keep_alive = true;
      else if (resp_header_copy (resp, "Connection", hdrval, sizeof (hdrval)))
        {
          if (0 == strcasecmp (hdrval, "Keep-Alive"))
            keep_alive = true;
        }
    }
  if (keep_alive)
    /* The server has promised that it will not close the connection
       when we're done.  This means that we can register it.  */
    register_persistent (conn->host, conn->port, sock, using_ssl);

  if (statcode == HTTP_STATUS_UNAUTHORIZED)
    {
      /* Authorization is required.  */
      if (keep_alive && !head_only && skip_short_body (sock, contlen))
        CLOSE_FINISH (sock);
      else
        CLOSE_INVALIDATE (sock);
      pconn.authorized = false;
      if (!auth_finished && (user && passwd))
        {
          /* IIS sends multiple copies of WWW-Authenticate, one with
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
              char *pth;
              pth = url_full_path (u);
              request_set_header (req, "Authorization",
                                  create_authorization_line (www_authenticate,
                                                             user, passwd,
                                                             request_method (req),
                                                             pth,
                                                             &auth_finished),
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
      return AUTHFAILED;
    }
  else /* statcode != HTTP_STATUS_UNAUTHORIZED */
    {
      /* Kludge: if NTLM is used, mark the TCP connection as authorized. */
      if (ntlm_seen)
        pconn.authorized = true;
    }
  request_free (req);

  hs->statcode = statcode;
