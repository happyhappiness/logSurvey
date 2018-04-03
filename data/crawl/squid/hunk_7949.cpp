 	}
 	xfree(p);
     }
-    /* open error logging file */
-    if (logfile != NULL) {
-	if (debug_log_file)
-	    free(debug_log_file);
-	debug_log_file = strdup(logfile);	/* keep a static copy */
-	debug_log = fopen(logfile, "a+");
-	if (!debug_log) {
-	    fprintf(stderr, "WARNING: Cannot write log file: %s\n", logfile);
-	    perror(logfile);
-	    fprintf(stderr, "         messages will be sent to 'stderr'.\n");
-	    fflush(stderr);
-	    debug_log = stderr;
-	    /* avoid reduntancy */
-	    stderr_enable = 0;
-	}
-    } else {
-	fprintf(stderr, "WARNING: No log file specified?\n");
-	fprintf(stderr, "         messages will be sent to 'stderr'.\n");
-	fflush(stderr);
-	debug_log = stderr;
-	stderr_enable = 0;
-    }
+
+    debugOpenLog(logfile);
 
 #if HAVE_SYSLOG
     if (syslog_enable)
