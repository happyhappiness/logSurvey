 display_image (char *buf)
 {
   bool old = log_set_save_context (false);
-  logputs (LOG_VERBOSE, "\r");
-  logputs (LOG_VERBOSE, buf);
+  logputs (LOG_PROGRESS, "\r");
+  logputs (LOG_PROGRESS, buf);
   log_set_save_context (old);
 }
 
