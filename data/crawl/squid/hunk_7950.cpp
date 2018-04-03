     }
     /* Close and reopen the log.  It may have been renamed "manually"
      * before HUP'ing us. */
-    fclose(debug_log);
-    debug_log = fopen(debug_log_file, "a+");
-    if (debug_log == NULL) {
-	fprintf(stderr, "WARNING: Cannot write log file: %s\n",
-	    debug_log_file);
-	perror(debug_log_file);
-	fprintf(stderr, "         messages will be sent to 'stderr'.\n");
-	fflush(stderr);
-	debug_log = stderr;
-	/* avoid redundancy */
-	stderr_enable = 0;
+    if (debug_log != stderr) {
+	fclose(debug_log);
+	debugOpenLog(debug_log_file);
     }
 }
