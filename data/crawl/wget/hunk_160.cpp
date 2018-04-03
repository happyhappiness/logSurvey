         }
     }
 
+  if (cond_get)
+    {
+      if (statcode == HTTP_STATUS_NOT_MODIFIED)
+        {
+          logprintf (LOG_VERBOSE,
+                     _("File %s not modified on server. Omitting download.\n\n"),
+                     quote (hs->local_file));
+          *dt |= RETROKF;
+          CLOSE_FINISH (sock);
+          retval = RETRUNNEEDED;
+          goto cleanup;
+        }
+      /* Handle the case when server ignores If-Modified-Since header.  */
+      else if (statcode == HTTP_STATUS_OK && hs->remote_time)
+        {
+          time_t tmr = http_atotm (hs->remote_time);
+
+          /* Check if the local file is up-to-date based on Last-Modified header
+             and content length.  */
+          if (tmr != (time_t) - 1 && tmr <= hs->orig_file_tstamp
+              && (contlen == -1 || contlen == hs->orig_file_size))
+            {
+              logprintf (LOG_VERBOSE,
+                         _("Server ignored If-Modified-Since header for file %s.\n"
+                           "You might want to add --no-if-modified-since option."
+                           "\n\n"),
+                         quote (hs->local_file));
+              *dt |= RETROKF;
+              CLOSE_INVALIDATE (sock);
+              retval = RETRUNNEEDED;
+              goto cleanup;
+            }
+        }
+    }
+
   if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE
       || (!opt.timestamping && hs->restval > 0 && statcode == HTTP_STATUS_OK
           && contrange == 0 && contlen >= 0 && hs->restval >= contlen))
