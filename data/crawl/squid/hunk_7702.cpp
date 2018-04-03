 #if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
     storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
     getrusage(RUSAGE_SELF, &rusage);
-    storeAppendPrintf(sentry, "{\tCPU Usage: user %d sys %d}\n",
-	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
+    storeAppendPrintf(sentry, "{\tCPU Time: %d seconds (%d user %d sys)}\n",
+	(int) rusage.ru_utime.tv_sec + (int) rusage.ru_stime.tv_sec,
+	(int) rusage.ru_utime.tv_sec,
+	(int) rusage.ru_stime.tv_sec);
+    storeAppendPrintf(sentry, "{\tCPU Usage: %d%%}\n",
+	percent(rusage.ru_utime.tv_sec + rusage.ru_stime.tv_sec,
+	    squid_curtime - squid_starttime));
     storeAppendPrintf(sentry, "{\tProcess Size: rss %ld KB}\n",
 	rusage.ru_maxrss * getpagesize() >> 10);
-
     storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
 	rusage.ru_majflt);
-
 #endif
 
 #if HAVE_MALLINFO
     mp = mallinfo();
-    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n", appname
-	);
+    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n",
+	appname);
     storeAppendPrintf(sentry, "{\tTotal space in arena:  %6d KB}\n",
 	mp.arena >> 10);
     storeAppendPrintf(sentry, "{\tOrdinary blocks:       %6d KB %6d blks}\n",
