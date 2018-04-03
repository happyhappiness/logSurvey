 
   print_download_speed (dp, dp->dots * dot_bytes
 			+ dp->accumulated
-			- dp->initial_length % row_bytes);
+			- dp->initial_length % row_bytes,
+			dltime);
   logputs (LOG_VERBOSE, "\n\n");
 
   log_set_flush (0);
 
-  wtimer_delete (dp->timer);
   xfree (dp);
 }
 
