 }
 
 static void
-fwdLog(FwdState * fwdState)
+FwdState::log()
 {
     if (NULL == logfile)
         return;
 
     logfilePrintf(logfile, "%9d.%03d %03d %s %s\n",
                   (int) current_time.tv_sec,
                   (int) current_time.tv_usec / 1000,
-                  fwdState->last_status,
-                  RequestMethodStr[fwdState->request->method],
-                  fwdState->request->canonical);
+                  last_status,
+                  RequestMethodStr[request->method],
+                  request->canonical);
 }
 
 void
-fwdStatus(FwdState * fwdState, http_status s)
+FwdState::status(http_status s)
 {
-    fwdState->last_status = s;
+    last_status = s;
 }
 
 #endif
