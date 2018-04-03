     fprintf(debug_log, "Squid Cache (Version %s): Terminated abnormally.\n",
 	version_string);
     fflush(debug_log);
-    PrintRusage(NULL, debug_log);
+    PrintRusage();
+    dumpMallocStats();
 }
 
 /* fatal */
