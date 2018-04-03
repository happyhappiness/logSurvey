           logprintf (LOG_NOTQUIET, _("%d redirections exceeded.\n"),
                      opt.max_redirect);
           url_free (newloc_parsed);
-          url_free (u);
+          if (orig_parsed != u)
+            {
+              url_free (u);
+            }
           xfree (url);
           xfree (mynewloc);
           RESTORE_POST_DATA;
