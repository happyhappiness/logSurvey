 #endif
                                   &host_lookup_failed))
         {
+          int family = socket_family (pconn.socket, ENDPOINT_PEER);
           sock = pconn.socket;
           using_ssl = pconn.ssl;
-          logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
-                     quotearg_style (escape_quoting_style, pconn.host),
-                     pconn.port);
+          if (family == AF_INET6)
+             logprintf (LOG_VERBOSE, _("Reusing existing connection to [%s]:%d.\n"),
+                        quotearg_style (escape_quoting_style, pconn.host),
+                         pconn.port);
+          else
+             logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
+                        quotearg_style (escape_quoting_style, pconn.host),
+                        pconn.port);
           DEBUGP (("Reusing fd %d.\n", sock));
           if (pconn.authorized)
             /* If the connection is already authorized, the "Basic"
