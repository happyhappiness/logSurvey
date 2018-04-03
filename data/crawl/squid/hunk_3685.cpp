     storeAppendPrintf(sentry, "avg service time: %d msec\n",
                       hlp->stats.avg_svc_time);
     storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "%7s\t%7s\t%7s\t%11s\t%20s\t%6s\t%7s\t%7s\t%7s\n",
+    storeAppendPrintf(sentry, "%7s\t%7s\t%7s\t%11s\t%6s\t%7s\t%7s\t%7s\n",
                       "#",
                       "FD",
                       "PID",
                       "# Requests",
-                      "# Deferred Requests",
-                      "Flags ",
+                      "Flags",
                       "Time",
                       "Offset",
                       "Request");
