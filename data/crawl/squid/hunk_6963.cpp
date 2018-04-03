 void
 info_get(StoreEntry * sentry)
 {
-    const char *tod = NULL;
-    float f;
-#if defined(HAVE_GETRUSAGE) && defined(RUSAGE_SELF)
     struct rusage rusage;
-#endif
+    double cputime;
+    double runtime;
 #if HAVE_MSTATS && HAVE_GNUMALLOC_H
     struct mstats ms;
 #elif HAVE_MALLINFO
     struct mallinfo mp;
     int t;
 #endif
 
+    runtime = tvSubDsec(squid_start, current_time);
+    if (runtime == 0.0)
+	runtime = 1.0;
     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n",
 	version_string);
-    tod = mkrfc1123(squid_starttime);
-    storeAppendPrintf(sentry, "{Start Time:\t%s}\n", tod);
-    tod = mkrfc1123(squid_curtime);
-    storeAppendPrintf(sentry, "{Current Time:\t%s}\n", tod);
+    storeAppendPrintf(sentry, "{Start Time:\t%s}\n",
+	mkrfc1123(squid_start.tv_sec));
+    storeAppendPrintf(sentry, "{Current Time:\t%s}\n",
+	mkrfc1123(current_time.tv_sec));
     storeAppendPrintf(sentry, "{Connection information for %s:}\n",
 	appname);
-    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n",
-	ntcpconn);
-    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
-	nudpconn);
-
-
-    f = (float) (squid_curtime - squid_starttime);
-    storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
-	f == 0.0 ? 0.0 : ((ntcpconn + nudpconn) / (f / 3600.0)));
+    storeAppendPrintf(sentry, "{\tNumber of HTTP requests received:\t%u}\n",
+	Counter.client_http.requests);
+    storeAppendPrintf(sentry, "{\tNumber of ICP messages received:\t%u}\n",
+	Counter.icp.pkts_recv);
+    storeAppendPrintf(sentry, "{\tNumber of ICP messages sent:\t%u}\n",
+	Counter.icp.pkts_sent);
+
+    storeAppendPrintf(sentry, "{\tHTTP requests per minute:\t%.1f}\n",
+	Counter.client_http.requests / (runtime / 60.0));
+    storeAppendPrintf(sentry, "{\tICP messages per minute:\t%.1f}\n",
+	(Counter.icp.pkts_sent + Counter.icp.pkts_recv) / (runtime / 60.0));
     storeAppendPrintf(sentry, "{\tSelect loop called: %d times, %0.3f ms avg}\n",
-	select_loops, 1000.0 * f / select_loops);
+	Counter.select_loops, 1000.0 * runtime / Counter.select_loops);
 
     storeAppendPrintf(sentry, "{Cache information for %s:}\n",
 	appname);
