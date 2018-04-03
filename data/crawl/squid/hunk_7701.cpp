     struct mallinfo mp;
 #endif
 
-    memset(line, '\0', SM_PAGE_SIZE);
-
     storeAppendPrintf(sentry, open_bracket);
-    storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n", version_string);
+    storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n",
+	version_string);
     tod = mkrfc850(&squid_starttime);
     storeAppendPrintf(sentry, "{Start Time:\t%s}\n", tod);
     tod = mkrfc850(&squid_curtime);
     storeAppendPrintf(sentry, "{Current Time:\t%s}\n", tod);
+    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
+	appname);
+    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n",
+	ntcpconn);
+    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
+	nudpconn);
 
-    /* -------------------------------------------------- */
-
-    storeAppendPrintf(sentry, "{Connection information for %s:}\n", appname);
-
-    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n", ntcpconn);
-
-    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n", nudpconn);
-
-    {
-	float f;
 	f = squid_curtime - squid_starttime;
-	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n", f == 0.0 ? 0.0 :
-	    ((ntcpconn + nudpconn) / (f / 3600)));
-    }
-
-    /* -------------------------------------------------- */
-
+	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
+	f == 0.0 ? 0.0 : ((ntcpconn + nudpconn) / (f / 3600)));
 
     storeAppendPrintf(sentry, "{Cache information for %s:}\n",
 	appname);
