   /* Check for status line.  */
   message = NULL;
   statcode = resp_status (resp, &message);
+  if (statcode < 0)
+    {
+      logprintf (LOG_NOTQUIET, _("Invalid server response.\n"));
+      CLOSE_INVALIDATE (sock);
+      request_free (req);
+      return HERR;
+    }
   hs->message = xstrdup (message);
   if (!opt.server_response)
     logprintf (LOG_VERBOSE, "%2d %s\n", statcode,
