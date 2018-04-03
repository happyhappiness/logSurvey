 }
 
 static void
-print_download_speed (struct dot_progress *dp, long bytes)
+print_download_speed (struct dot_progress *dp, long bytes, long dltime)
 {
-  long timer_value = wtimer_elapsed (dp->timer);
   logprintf (LOG_VERBOSE, " %s",
-	     retr_rate (bytes, timer_value - dp->last_timer_value, 1));
-  dp->last_timer_value = timer_value;
+	     retr_rate (bytes, dltime - dp->last_timer_value, 1));
+  dp->last_timer_value = dltime;
 }
 
 /* Dot-progress backend for progress_update. */
 
 static void
-dot_update (void *progress, long howmuch)
+dot_update (void *progress, long howmuch, long dltime)
 {
   struct dot_progress *dp = progress;
   int dot_bytes = opt.dot_bytes;
