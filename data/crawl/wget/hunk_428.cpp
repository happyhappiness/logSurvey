 
           resp = resp_new (head);
           statcode = resp_status (resp, &message);
+          if (statcode < 0)
+            {
+              logprintf (LOG_NOTQUIET, _("Invalid server response.\n"));
+              CLOSE_INVALIDATE (sock);
+              xfree (head);
+              return HERR;
+            }
           hs->message = xstrdup (message);
           resp_free (resp);
           xfree (head);
