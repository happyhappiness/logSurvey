               continue;
             }
           /* Maybe we should always keep track of broken links, not just in
-           * spider mode.  */
-          else if (opt.spider)
+           * spider mode.
+           * Don't log error if it was utf8 encoded because we will try
+           * one unencoded. */
+          else if (opt.spider && !get_utf8_encode ())
             {
               /* #### Again: ugly ugly ugly! */
-              if (!hurl) 
+              if (!hurl)
                 hurl = url_string (u, URL_AUTH_HIDE_PASSWD);
               nonexisting_url (hurl);
               logprintf (LOG_NOTQUIET, _("\
