   uerr_t err;
   char *robots_url = uri_merge (url, RES_SPECS_LOCATION);
   int saved_ts_val = opt.timestamping;
-  int saved_sp_val = opt.spider;
+  int saved_sp_val = opt.spider, url_err;
+  struct url * url_parsed;
 
   logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
   *file = NULL;
   opt.timestamping = false;
   opt.spider       = false;
-  err = retrieve_url (robots_url, file, NULL, NULL, NULL, false);
+
+  url_parsed = url_parse (robots_url, &url_err);
+  if (!url_parsed)
+    {
+      char *error = url_error (robots_url, url_err);
+      logprintf (LOG_NOTQUIET, "%s: %s.\n", robots_url, error);
+      xfree (error);
+      err = URLERROR;
+    }
+  else
+    {
+      err = retrieve_url (url_parsed, robots_url, file, NULL, NULL, NULL,
+                          false);
+      url_free(url_parsed);
+    }
+
   opt.timestamping = saved_ts_val;
   opt.spider       = saved_sp_val;  
   xfree (robots_url);
