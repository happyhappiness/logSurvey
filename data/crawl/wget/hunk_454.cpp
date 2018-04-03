           logputs (LOG_VERBOSE, "\n");
           logprintf (LOG_NOTQUIET, _("Cannot write to %s (%s).\n"),
                      quote (hstat.local_file), strerror (errno));
-        case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED: 
+        case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED:
         case SSLINITFAILED: case CONTNOTSUPPORTED: case VERIFCERTERR:
           /* Fatal errors just return from the function.  */
           ret = err;
