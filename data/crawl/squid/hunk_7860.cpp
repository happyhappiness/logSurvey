 #endif
     fprintf(debug_log, "FATAL: %s\n", message);
     fprintf(debug_log, "Harvest Cache (Version %s): Terminated abnormally.\n",
-	SQUID_VERSION);
+	version_string);
     fflush(debug_log);
     PrintRusage(NULL, debug_log);
 }