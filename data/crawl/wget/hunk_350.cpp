           logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
           ret = err;
           goto exit;
+        case UNLINKERR:
+          /* Another fatal error.  */
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("Cannot unlink %s (%s).\n"),
+                     quote (hstat.local_file), strerror (errno));
+          ret = err;
+          goto exit;
         case NEWLOCATION:
           /* Return the new location to the caller.  */
           if (!*newloc)
