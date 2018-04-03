           statcode = resp_status (resp, &message);
           if (statcode < 0)
             {
-              logprintf (LOG_NOTQUIET, _("Invalid server response.\n"));
-              CLOSE_INVALIDATE (sock);
+              char *tms = datetime_str (time (NULL));
+              logprintf (LOG_VERBOSE, "%d\n", statcode);
+              logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"), tms, statcode,
+                         quotearg_style (escape_quoting_style,
+                                         _("Malformed status line")));
               xfree (head);
               return HERR;
             }
