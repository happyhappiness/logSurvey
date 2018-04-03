        {
          int family = socket_family (pconn.socket, ENDPOINT_PEER);
          sock = pconn.socket;
          *using_ssl = pconn.ssl;
#if ENABLE_IPV6
          if (family == AF_INET6)
             logprintf (LOG_VERBOSE, _("Reusing existing connection to [%s]:%d.\n"),
