           /* Fatal errors just return from the function.  */
           ret = err;
           goto exit;
+        case WARC_ERR:
+          /* A fatal WARC error. */
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("Cannot write to WARC file..\n"));
+          ret = err;
+          goto exit;
+        case WARC_TMP_FOPENERR: case WARC_TMP_FWRITEERR:
+          /* A fatal WARC error. */
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("Cannot write to temporary WARC file.\n"));
+          ret = err;
+          goto exit;
         case CONSSLERR:
           /* Another fatal error.  */
           logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
