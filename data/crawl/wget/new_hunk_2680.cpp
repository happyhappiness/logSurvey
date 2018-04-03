  if (!inhibit_keep_alive)
    {
      /* Look for a persistent connection to target host, unless a
         proxy is used.  The exception is when SSL is in use, in which
         case the proxy is nothing but a passthrough to the target
         host, registered as a connection to the latter.  */
      struct url *relevant = conn;
#ifdef HAVE_SSL
      if (u->scheme == SCHEME_HTTPS)
        relevant = u;
#endif

      if (persistent_available_p (relevant->host, relevant->port,
#ifdef HAVE_SSL
                                  relevant->scheme == SCHEME_HTTPS,
#else
                                  0,
#endif
                                  &host_lookup_failed))
        {
          sock = pconn.socket;
          using_ssl = pconn.ssl;
          logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
                     escnonprint (pconn.host), pconn.port);
          DEBUGP (("Reusing fd %d.\n", sock));
          if (pconn.authorized)
            /* If the connection is already authorized, the "Basic"
               authorization added by code above is unnecessary and
               only hurts us.  */
            request_remove_header (req, "Authorization");
        }
    }

  if (sock < 0)
    {
      /* In its current implementation, persistent_available_p will
         look up conn->host in some cases.  If that lookup failed, we
         don't need to bother with connect_to_host.  */
      if (host_lookup_failed)
        {
          request_free (req);
          return HOSTERR;
        }

      sock = connect_to_host (conn->host, conn->port);
      if (sock == E_HOST)
        {
          request_free (req);
          return HOSTERR;
        }
      else if (sock < 0)
        {
          request_free (req);
          return (retryable_socket_connect_error (errno)
                  ? CONERROR : CONIMPOSSIBLE);
        }

#ifdef HAVE_SSL
      if (proxy && u->scheme == SCHEME_HTTPS)
        {
          /* When requesting SSL URLs through proxies, use the
             CONNECT method to request passthrough.  */
          struct request *connreq = request_new ();
          request_set_method (connreq, "CONNECT",
                              aprintf ("%s:%d", u->host, u->port));
          SET_USER_AGENT (connreq);
          if (proxyauth)
            {
              request_set_header (connreq, "Proxy-Authorization",
                                  proxyauth, rel_value);
              /* Now that PROXYAUTH is part of the CONNECT request,
                 zero it out so we don't send proxy authorization with
                 the regular request below.  */
              proxyauth = NULL;
            }
          /* Examples in rfc2817 use the Host header in CONNECT
             requests.  I don't see how that gains anything, given
             that the contents of Host would be exactly the same as
             the contents of CONNECT.  */

          write_error = request_send (connreq, sock);
          request_free (connreq);
          if (write_error < 0)
            {
              CLOSE_INVALIDATE (sock);
              return WRITEFAILED;
            }

          head = read_http_response_head (sock);
          if (!head)
            {
              logprintf (LOG_VERBOSE, _("Failed reading proxy response: %s\n"),
                         fd_errstr (sock));
              CLOSE_INVALIDATE (sock);
              return HERR;
            }
          message = NULL;
          if (!*head)
            {
              xfree (head);
              goto failed_tunnel;
            }
          DEBUGP (("proxy responded with: [%s]\n", head));

          resp = resp_new (head);
          statcode = resp_status (resp, &message);
          resp_free (resp);
          xfree (head);
          if (statcode != 200)
            {
            failed_tunnel:
              logprintf (LOG_NOTQUIET, _("Proxy tunneling failed: %s"),
                         message ? escnonprint (message) : "?");
              xfree_null (message);
              return CONSSLERR;
            }
          xfree_null (message);

          /* SOCK is now *really* connected to u->host, so update CONN
             to reflect this.  That way register_persistent will
             register SOCK as being connected to u->host:u->port.  */
          conn = u;
        }

      if (conn->scheme == SCHEME_HTTPS)
        {
          if (!ssl_connect (sock) || !ssl_check_certificate (sock, u->host))
            {
              fd_close (sock);
              return CONSSLERR;
            }
          using_ssl = true;
        }
#endif /* HAVE_SSL */
    }

