           char *error = url_error (mynewloc, up_error_code);
           logprintf (LOG_NOTQUIET, "%s: %s.\n", escnonprint_uri (mynewloc),
                      error);
-          url_free (u);
+          if (orig_parsed != u)
+            {
+              url_free (u);
+            }
           xfree (url);
           xfree (mynewloc);
           xfree (error);
