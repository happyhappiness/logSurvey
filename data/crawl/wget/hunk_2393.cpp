                only hurts us.  */
             request_remove_header (req, "Authorization");
         }
-    }
-
-  if (sock < 0)
-    {
-      /* In its current implementation, persistent_available_p will
-         look up conn->host in some cases.  If that lookup failed, we
-         don't need to bother with connect_to_host.  */
-      if (host_lookup_failed)
+      else if (host_lookup_failed)
         {
           request_free (req);
           logprintf(LOG_NOTQUIET,
