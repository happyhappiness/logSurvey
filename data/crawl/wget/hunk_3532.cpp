 static void
 display_image (char *buf)
 {
-  int len = strlen (buf);
-  char *del_buf = alloca (len + 1);
-
-  logputs (LOG_VERBOSE, buf);
-
-  memset (del_buf, '\b', len);
-  del_buf[len] = '\0';
-
+  char *del_buf = alloca (screen_width + 1);
+  memset (del_buf, '\b', screen_width);
+  del_buf[screen_width] = '\0';
   logputs (LOG_VERBOSE, del_buf);
+  logputs (LOG_VERBOSE, buf);
 }
 
 static void
