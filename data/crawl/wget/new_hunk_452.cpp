          sock = pconn.socket;
          using_ssl = pconn.ssl;
          logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
                     quotearg_style (escape_quoting_style, pconn.host),
                     pconn.port);
          DEBUGP (("Reusing fd %d.\n", sock));
          if (pconn.authorized)
