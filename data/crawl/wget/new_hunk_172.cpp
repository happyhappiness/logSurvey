          if (proxyauth)
            {
              request_set_header (connreq, "Proxy-Authorization",
                                  *proxyauth, rel_value);
              /* Now that PROXYAUTH is part of the CONNECT request,
                 zero it out so we don't send proxy authorization with
                 the regular request below.  */
              *proxyauth = NULL;
            }
          request_set_header (connreq, "Host",
                              aprintf ("%s:%d", u->host, u->port),
