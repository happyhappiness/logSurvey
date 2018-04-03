 void
 touch (const char *file, time_t tm)
 {
-#if HAVE_UTIME
-# ifdef HAVE_STRUCT_UTIMBUF
   struct utimbuf times;
-# else
-  struct {
-    time_t actime;
-    time_t modtime;
-  } times;
-# endif
+
   times.modtime = tm;
   times.actime = time (NULL);
+
   if (utime (file, &times) == -1)
     logprintf (LOG_NOTQUIET, "utime(%s): %s\n", file, strerror (errno));
-#else
-  struct timespec timespecs[2];
-  int fd;
-
-  fd = open (file, O_WRONLY);
-  if (fd < 0)
-    {
-      logprintf (LOG_NOTQUIET, "open(%s): %s\n", file, strerror (errno));
-      return;
-    }
-
-  timespecs[0].tv_sec = time (NULL);
-  timespecs[0].tv_nsec = 0L;
-  timespecs[1].tv_sec = tm;
-  timespecs[1].tv_nsec = 0L;
-
-  if (futimens (fd, timespecs) == -1)
-    logprintf (LOG_NOTQUIET, "futimens(%s): %s\n", file, strerror (errno));
-
-  close (fd);
-#endif
 }
 
 /* Checks if FILE is a symbolic link, and removes it if it is.  Does
