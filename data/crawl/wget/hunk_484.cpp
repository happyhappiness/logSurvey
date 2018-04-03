              time. */
           char *hurl = url_string (u, URL_AUTH_HIDE_PASSWD);
           logprintf (LOG_NONVERBOSE, "%s URL: %s [%s] -> \"%s\" [%d]\n",
-                     tms, hurl, number_to_static_string (len), locf, count);
+                     tms, hurl, number_to_static_string (qtyread), locf, count);
           xfree (hurl);
         }
 
