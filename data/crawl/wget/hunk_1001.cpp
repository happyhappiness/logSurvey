       proxy_url = url_parse (proxy, &up_error_code);
       if (!proxy_url)
         {
+          char *error = url_error (proxy, up_error_code);
           logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
-                     proxy, url_error (up_error_code));
+                     proxy, error);
           xfree (url);
+          xfree (error);
           RESTORE_POST_DATA;
           return PROXERR;
         }
