 static void
 display_image (char *buf)
 {
-  bool old = log_set_save_context (false);
-  logputs (LOG_PROGRESS, "\r");
-  logputs (LOG_PROGRESS, buf);
-  log_set_save_context (old);
+  if (tcgetpgrp (fileno (stderr)) == getpid ()) {
+    bool old = log_set_save_context (false);
+    logputs (LOG_PROGRESS, "\r");
+    logputs (LOG_PROGRESS, buf);
+    log_set_save_context (old);
+  }
 }
 
 static void
