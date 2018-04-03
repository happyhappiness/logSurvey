 void
 touch (const char *file, time_t tm)
 {
-  struct timeval timevals[2];
+  struct timespec timespecs[2];
+  int fd;
+
+  fd = open (file, O_WRONLY);
+  if (fd < 0)
+    {
+      logprintf (LOG_NOTQUIET, "open(%s): %s\n", file, strerror (errno));
+      return;
+    }
+
+  timespecs[0].tv_sec = time (NULL);
+  timespecs[0].tv_nsec = 0L;
+  timespecs[1].tv_sec = tm;
+  timespecs[1].tv_nsec = 0L;
 
-  timevals[0].tv_sec = time (NULL);
-  timevals[0].tv_usec = 0L;
-  timevals[1].tv_sec = tm;
-  timevals[1].tv_usec = 0L;
+  if (futimens (fd, timespecs) == -1)
+    logprintf (LOG_NOTQUIET, "futimens(%s): %s\n", file, strerror (errno));
 
-  if (utimes (file, timevals) == -1)
-    logprintf (LOG_NOTQUIET, "utimes(%s): %s\n", file, strerror (errno));
+  close (fd);
 }
 
 /* Checks if FILE is a symbolic link, and removes it if it is.  Does
