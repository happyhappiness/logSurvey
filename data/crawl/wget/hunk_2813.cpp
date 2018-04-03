 static void
 print_download_speed (struct dot_progress *dp, wgint bytes, double dltime)
 {
-  logprintf (LOG_VERBOSE, " %s",
-	     retr_rate (bytes, dltime - dp->last_timer_value, 1));
+  logprintf (LOG_VERBOSE, " %7s",
+	     retr_rate (bytes, dltime - dp->last_timer_value));
   dp->last_timer_value = dltime;
 }
 
