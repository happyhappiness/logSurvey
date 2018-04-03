 
     /* -------------------------------------------------- */
 
-    sprintf(line, "{Connection information for %s:}\n", appname);
-    storeAppend(sentry, line, strlen(line));
-
-    sprintf(line, "{\tNumber of TCP connections:\t%lu}\n", ntcpconn);
-    storeAppend(sentry, line, strlen(line));
-
-    sprintf(line, "{\tNumber of UDP connections:\t%lu}\n", ndupconn);
-    storeAppend(sentry, line, strlen(line));
+    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
+	appname);
+    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n",
+	ntcpconn);
+    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
+	nudpconn);
 
     {
 	float f;
 	f = squid_curtime - squid_starttime;
-	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n", f == 0.0 ? 0.0 :
-	    (nconn / (f / 3600)));
+	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
+		f == 0.0 ? 0.0 :
+	    ((ntcpconn + nudpconn) / (f / 3600)));
     }
 
     /* -------------------------------------------------- */
 
-
-
     storeAppendPrintf(sentry, "{Cache information for %s:}\n", appname);
 
     storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d MB}\n", storeGetSwapSize() >> 10);
