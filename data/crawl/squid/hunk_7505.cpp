 {
 #if HAVE_SYSLOG
     if (opt_syslog_enable)
-	syslog(LOG_ALERT, message);
+	syslog(LOG_ALERT, "%s", message);
 #endif
     fprintf(debug_log, "FATAL: %s\n", message);
     fprintf(debug_log, "Squid Cache (Version %s): Terminated abnormally.\n",