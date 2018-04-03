 
     /* -------------------------------------------------- */
 
-    storeAppendPrintf(sentry, "{Connection information for %s:}\n", appname);
+    sprintf(line, "{Connection information for %s:}\n", appname);
+    storeAppend(sentry, line, strlen(line));
 
-    storeAppendPrintf(sentry, "{\tNumber of connections:\t%lu}\n", nconn);
+    sprintf(line, "{\tNumber of TCP connections:\t%lu}\n", ntcpconn);
+    storeAppend(sentry, line, strlen(line));
+
+    sprintf(line, "{\tNumber of UDP connections:\t%lu}\n", ndupconn);
+    storeAppend(sentry, line, strlen(line));
 
     {
 	float f;
