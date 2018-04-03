 static void
 display_image (char *buf)
 {
-  if (tcgetpgrp (fileno (stderr)) == getpid ()) {
-    bool old = log_set_save_context (false);
-    logputs (LOG_PROGRESS, "\r");
-    logputs (LOG_PROGRESS, buf);
-    log_set_save_context (old);
-  }
+  bool old = log_set_save_context (false);
+  logputs (LOG_PROGRESS, "\r");
+  logputs (LOG_PROGRESS, buf);
+  log_set_save_context (old);
 }
 
 static void
