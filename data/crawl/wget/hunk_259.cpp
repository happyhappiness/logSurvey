           logputs (LOG_VERBOSE, "\n");
           logprintf (LOG_NOTQUIET, _("Cannot write to %s (%s).\n"),
                      quote (hstat.local_file), strerror (errno));
-        case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED:
-        case SSLINITFAILED: case CONTNOTSUPPORTED: case VERIFCERTERR:
-        case FILEBADFILE:
+        case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case SSLINITFAILED:
+        case CONTNOTSUPPORTED: case VERIFCERTERR: case FILEBADFILE:
+        case UNKNOWNATTR:
           /* Fatal errors just return from the function.  */
           ret = err;
           goto exit;
+        case ATTRMISSING:
+          /* A missing attribute in a Header is a fatal Protocol error. */
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("Required attribute missing from Header received.\n"));
+          ret = err;
+          goto exit;
+        case AUTHFAILED:
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("Username/Password Authentication Failed.\n"));
+          ret = err;
+          goto exit;
         case WARC_ERR:
           /* A fatal WARC error. */
           logputs (LOG_VERBOSE, "\n");
