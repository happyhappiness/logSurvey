                 the regular request below.  */
              proxyauth = NULL;
            }
          request_set_header (connreq, "Host",
                              aprintf ("%s:%d", u->host, u->port),
                              rel_value);

          write_error = request_send (connreq, sock, 0);
          request_free (connreq);
