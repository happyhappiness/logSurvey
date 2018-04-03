 void
 touch (const char *file, time_t tm)
 {
+#if HAVE_UTIME
+# ifdef HAVE_STRUCT_UTIMBUF
+  struct utimbuf times;
+# else
+  struct {
+    time_t actime;
+    time_t modtime;
+  } times;
+# endif
+  times.modtime = tm;
+  times.actime = time (NULL);
+  if (utime (file, &times) == -1)
+    logprintf (LOG_NOTQUIET, "utime(%s): %s\n", file, strerror (errno));
+#else
   struct timespec timespecs[2];
   int fd;
 
