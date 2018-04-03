 dot_finish (void *progress, double dltime)
 {
   struct dot_progress *dp = progress;
-  int dot_bytes = opt.dot_bytes;
-  wgint row_bytes = opt.dot_bytes * opt.dots_in_line;
+  wgint ROW_BYTES = opt.dot_bytes * opt.dots_in_line;
   int i;
 
   log_set_flush (false);
 
   if (dp->dots == 0)
-    logprintf (LOG_VERBOSE, "\n%5ldK", (long) (dp->rows * row_bytes / 1024));
+    logprintf (LOG_VERBOSE, "\n%6sK",
+	       number_to_static_string (dp->rows * ROW_BYTES / 1024));
   for (i = dp->dots; i < opt.dots_in_line; i++)
     {
       if (i % opt.dot_spacing == 0)
 	logputs (LOG_VERBOSE, " ");
       logputs (LOG_VERBOSE, " ");
     }
-  if (dp->total_length)
-    {
-      print_percentage (dp->rows * row_bytes
-			+ dp->dots * dot_bytes
-			+ dp->accumulated,
-			dp->total_length);
-    }
-
-  {
-    wgint row_qty = dp->dots * dot_bytes + dp->accumulated;
-    if (dp->rows == dp->initial_length / row_bytes)
-      row_qty -= dp->initial_length % row_bytes;
-    print_download_speed (dp, row_qty, dltime);
-  }
 
+  print_row_stats (dp, dltime, true);
   logputs (LOG_VERBOSE, "\n\n");
   log_set_flush (false);
 
