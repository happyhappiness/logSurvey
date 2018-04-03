       /* ... but some HTTP/1.0 caches doesn't implement Cache-Control.  */
       request_set_header (req, "Pragma", "no-cache", rel_none);
     }
+  if (*dt & IF_MODIFIED_SINCE)
+    {
+      char strtime[32];
+      uerr_t err = time_to_rfc1123 (hs->orig_file_tstamp, strtime, countof (strtime));
+
+      if (err != RETROK)
+        {
+          logputs (LOG_VERBOSE, _("Cannot convert timestamp to http format. "
+                                  "Falling back to time 0 as last modification "
+                                  "time.\n"));
+          strcpy (strtime, "Thu, 01 Jan 1970 00:00:00 GMT");
+        }
+      request_set_header (req, "If-Modified-Since", xstrdup (strtime), rel_value);
+    }
   if (hs->restval)
     request_set_header (req, "Range",
                         aprintf ("bytes=%s-",
