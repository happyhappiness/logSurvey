     storeAppendPrintf(sentry, "avg service time: %d msec\n",
                       hlp->stats.avg_svc_time);
     storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "%7s\t%7s\t%7s\t%11s\t%20s\t%s\t%7s\t%7s\t%7s\n",
+    storeAppendPrintf(sentry, "%7s\t%7s\t%7s\t%11s\t%s\t%7s\t%7s\t%7s\n",
                       "#",
                       "FD",
                       "PID",
                       "# Requests",
-                      "# Deferred Requests",
                       "Flags",
                       "Time",
                       "Offset",
