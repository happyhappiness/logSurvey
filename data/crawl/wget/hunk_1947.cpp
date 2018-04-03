         case FWRITEERR: case FOPENERR:
           /* Another fatal error.  */
           logputs (LOG_VERBOSE, "\n");
-          logprintf (LOG_NOTQUIET, _("Cannot write to `%s' (%s).\n"),
-                     hstat.local_file, strerror (errno));
+          logprintf (LOG_NOTQUIET, _("Cannot write to %s (%s).\n"),
+                     quote (hstat.local_file), strerror (errno));
         case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED: 
         case SSLINITFAILED: case CONTNOTSUPPORTED:
           /* Fatal errors just return from the function.  */
