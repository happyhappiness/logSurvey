         if (checklist && log->aclList && !checklist->matchAclListFast(log->aclList))
             continue;
 
-        switch (log->type) {
-
-        case CLF_AUTO:
-
-            if (Config.onoff.common_log)
-                accessLogCommon(al, log->logfile);
-            else
-                accessLogSquid(al, log->logfile);
-
-            break;
+        if (log->logfile) {
+            logfileLineStart(log->logfile);
 
-        case CLF_SQUID:
-            accessLogSquid(al, log->logfile);
+            switch (log->type) {
 
-            break;
-
-        case CLF_COMMON:
-            accessLogCommon(al, log->logfile);
+            case CLF_AUTO:
+                if (Config.onoff.common_log)
+                    accessLogCommon(al, log->logfile);
+                else
+                    accessLogSquid(al, log->logfile);
+                break;
 
-            break;
+            case CLF_SQUID:
+                accessLogSquid(al, log->logfile);
+                break;
 
-        case CLF_CUSTOM:
-            accessLogCustom(al, log);
+            case CLF_COMMON:
+                accessLogCommon(al, log->logfile);
+                break;
 
-            break;
+            case CLF_CUSTOM:
+                accessLogCustom(al, log);
+                break;
 
 #if ICAP_CLIENT
-        case CLF_ICAP_SQUID:
-            accessLogICAPSquid(al, log->logfile);
-
-            break;
+            case CLF_ICAP_SQUID:
+                accessLogICAPSquid(al, log->logfile);
+                break;
 #endif
 
-        case CLF_NONE:
-            goto last;
+            case CLF_NONE:
+                return; // abort!
 
-        default:
-            fatalf("Unknown log format %d\n", log->type);
+            default:
+                fatalf("Unknown log format %d\n", log->type);
+                break;
+            }
 
-            break;
+            logfileLineEnd(log->logfile);
         }
 
-        logfileFlush(log->logfile);
-
+        // NP:  WTF?  if _any_ log line has no checklist ignore the following ones?
         if (!checklist)
             break;
     }
-
-last:
-    (void)0; /* NULL statement for label */
 }
 
 void
