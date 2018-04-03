 
     ms = mstats();
 
-    storeAppendPrintf(sentry, "Memory usage for %s via mstats():\n",
-                      appname);
+    storeAppendPrintf(sentry, "Memory usage for %s via mstats():\n",APP_SHORTNAME);
 
     storeAppendPrintf(sentry, "\tTotal space in arena:  %6d KB\n",
                       ms.bytes_total >> 10);
