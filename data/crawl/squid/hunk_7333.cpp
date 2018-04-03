     storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
 	nudpconn);
 
+
     f = (float) (squid_curtime - squid_starttime);
     storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
 	f == 0.0 ? 0.0 : ((ntcpconn + nudpconn) / (f / 3600.0)));
+    storeAppendPrintf(sentry, "{\tSelect loop called: %d times, %0.3f ms avg}\n",
+	select_loops, 1000.0 * f / select_loops);
 
     storeAppendPrintf(sentry, "{Cache information for %s:}\n",
 	appname);
