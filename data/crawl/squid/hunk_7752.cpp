 
     memset(line, '\0', SM_PAGE_SIZE);
 
-    storeAppendPrintf(sentry, "{\n");
-
+    storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n", version_string);
-
     tod = mkrfc850(&squid_starttime);
-
     storeAppendPrintf(sentry, "{Start Time:\t%s}\n", tod);
-
     tod = mkrfc850(&squid_curtime);
     storeAppendPrintf(sentry, "{Current Time:\t%s}\n", tod);
 
     /* -------------------------------------------------- */
 
-    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
-	appname);
-    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n",
-	ntcpconn);
-    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
-	nudpconn);
+    storeAppendPrintf(sentry, "{Connection information for %s:}\n", appname);
+
+    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n", ntcpconn);
+
+    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n", nudpconn);
 
     {
 	float f;
 	f = squid_curtime - squid_starttime;
-	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
-	    f == 0.0 ? 0.0 :
+	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n", f == 0.0 ? 0.0 :
 	    ((ntcpconn + nudpconn) / (f / 3600)));
     }
 
     /* -------------------------------------------------- */
 
-    storeAppendPrintf(sentry, "{Cache information for %s:}\n", appname);
-
-    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d MB}\n", storeGetSwapSize() >> 10);
-
-    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n", storeGetMemSize() >> 10);
 
+    storeAppendPrintf(sentry, "{Cache information for %s:}\n",
+	appname);
+    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d MB}\n",
+	storeGetSwapSize() >> 10);
+    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n",
+	storeGetMemSize() >> 10);
     tod = mkrfc850(&next_cleaning);
     storeAppendPrintf(sentry, "{\tStorage Expiration at:\t%s}\n", tod);
 
-#if defined(HAVE_GETRUSAGE) && defined(RUSAGE_SELF)
+#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
     storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
-
     getrusage(RUSAGE_SELF, &rusage);
-    storeAppendPrintf(sentry, "{\tCPU Usage: user %d sys %d}\n{\tProcess Size: rss %d KB}\n",
-	rusage.ru_utime.tv_sec, rusage.ru_stime.tv_sec,
+    storeAppendPrintf(sentry, "{\tCPU Usage: user %d sys %d}\n",
+	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
+    storeAppendPrintf(sentry, "{\tProcess Size: rss %ld KB}\n",
 	rusage.ru_maxrss * getpagesize() >> 10);
 
-    storeAppendPrintf(sentry, "{\tPage faults with physical i/o:\t%d}\n",
+    storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
 	rusage.ru_majflt);
 
 #endif
 
 #if HAVE_MALLINFO
     mp = mallinfo();
-
-    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n", appname);
-
-    storeAppendPrintf(sentry, "{\ttotal space in arena:\t%d KB}\n", mp.arena >> 10);
-    storeAppendPrintf(sentry, "{\tnumber of ordinary blocks:\t%d}\n", mp.ordblks);
-    storeAppendPrintf(sentry, "{\tnumber of small blocks:\t%d}\n", mp.smblks);
-    if (mp.hblks) {
-	storeAppendPrintf(sentry, "{\tnumber of holding blocks:\t%d}\n", mp.hblks);
-    }
-    if (mp.hblkhd) {
-	storeAppendPrintf(sentry, "{\tspace in holding block headers:\t%d}\n", mp.hblkhd);
-    }
-    if (mp.usmblks) {
-	storeAppendPrintf(sentry, "{\tspace in small blocks in use:\t%d}\n", mp.usmblks);
-    }
-    if (mp.fsmblks) {
-	storeAppendPrintf(sentry, "{\tspace in free blocks:\t%d}\n", mp.fsmblks);
-    }
-    storeAppendPrintf(sentry, "{\tspace in ordinary blocks in use:\t%d KB}\n",
-	mp.uordblks >> 10);
-    storeAppendPrintf(sentry, "{\tspace in free ordinary blocks:\t%d KB}\n", mp.fordblks >> 10);
-    if (mp.keepcost) {
-	storeAppendPrintf(sentry, "{\tcost of enabling keep option:\t%d}\n", mp.keepcost);
-    }
+    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n", appname
+);
+    storeAppendPrintf(sentry, "{\tTotal space in arena:  %6d KB}\n",
+        mp.arena >> 10);
+    storeAppendPrintf(sentry, "{\tOrdinary blocks:       %6d KB %6d blks}\n",
+	mp.uordblks >> 10, mp.ordblks);
+    storeAppendPrintf(sentry, "{\tSmall blocks:          %6d KB %6d blks}\n",
+	mp.usmblks >> 10, mp.smblks);
+    storeAppendPrintf(sentry, "{\tHolding blocks:        %6d KB %6d blks}\n",
+	mp.hblkhd >> 10, mp.hblks);
+    storeAppendPrintf(sentry, "{\tFree Small blocks:     %6d KB}\n",
+	mp.fsmblks >> 10);
+    storeAppendPrintf(sentry, "{\tFree Ordinary blocks:  %6d KB}\n",
+	mp.fordblks >> 10);
+    t = mp.uordblks + mp.usmblks + mp.hblkhd;
+    storeAppendPrintf(sentry, "{\tTotal in use:          %6d KB %d%%}\n",
+	t >> 10, percent(t, mp.arena));
+    t = mp.fsmblks + mp.fordblks;
+    storeAppendPrintf(sentry, "{\tTotal free:            %6d KB %d%%}\n",
+	t >> 10, percent(t, mp.arena));
+#ifdef WE_DONT_USE_KEEP
+    storeAppendPrintf(sentry, "{\tKeep option:           %6d KB}\n",
+	mp.keepcost >> 10);
+#endif
 #if HAVE_EXT_MALLINFO
     storeAppendPrintf(sentry, "{\tmax size of small blocks:\t%d}\n", mp.mxfast);
     storeAppendPrintf(sentry, "{\tnumber of small blocks in a holding block:\t%d}\n",
