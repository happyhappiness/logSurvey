 	debugLevels[i] = l;
 }
 
-void _db_init(prefix, logfile)
-     char *prefix;
+static void debugOpenLog(logfile)
+     char *logfile;
+{
+    if (logfile == NULL) {
+	debug_log = stderr;
+	return;
+    }
+    if (debug_log_file)
+	free(debug_log_file);
+    debug_log_file = xstrdup(logfile);	/* keep a static copy */
+    debug_log = fopen(logfile, "a+");
+    if (!debug_log) {
+	fprintf(stderr, "WARNING: Cannot write log file: %s\n", logfile);
+	perror(logfile);
+	fprintf(stderr, "         messages will be sent to 'stderr'.\n");
+	fflush(stderr);
+	debug_log = stderr;
+    }
+}
+
+void _db_init(logfile)
      char *logfile;
 {
     int i;
