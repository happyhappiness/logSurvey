     if (user && !*user)
         safe_free(user);
 
-        logfilePrintf(logfile, "%9ld.%03d %6d %s -/%03d %"PRId64" %s %s %s -/%s -\n",
-                      (long int) current_time.tv_sec,
-                      (int) current_time.tv_usec / 1000,
+    logfilePrintf(logfile, "%9ld.%03d %6d %s -/%03d %"PRId64" %s %s %s -/%s -\n",
+                  (long int) current_time.tv_sec,
+                  (int) current_time.tv_usec / 1000,
 
-                      al->icap.trTime,
-                      client,
+                  al->icap.trTime,
+                  client,
 
-                      al->icap.resStatus,
-                      al->icap.bytesRead,
-                      Adaptation::Icap::ICAP::methodStr(al->icap.reqMethod),
-                      al->icap.reqUri.termedBuf(),
-                      user ? user : dash_str,
-                      al->icap.hostAddr.NtoA(tmp, MAX_IPSTRLEN));
+                  al->icap.resStatus,
+                  al->icap.bytesRead,
+                  Adaptation::Icap::ICAP::methodStr(al->icap.reqMethod),
+                  al->icap.reqUri.termedBuf(),
+                  user ? user : dash_str,
+                  al->icap.hostAddr.NtoA(tmp, MAX_IPSTRLEN));
     safe_free(user);
 }
 #endif
 
-void 
+void
 accessLogLogTo(customlog* log, AccessLogEntry * al, ACLChecklist * checklist)
 {
 