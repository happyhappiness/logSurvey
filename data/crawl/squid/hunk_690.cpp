     return srv->data;
 }
 
-/**
- * Dump some stats about the helper states to a StoreEntry
- */
 void
-helperStats(StoreEntry * sentry, helper * hlp, const char *label)
+helper::packStatsInto(Packable *p, const char *label) const
 {
-    if (!helperStartStats(sentry, hlp, label))
-        return;
-
-    storeAppendPrintf(sentry, "program: %s\n",
-                      hlp->cmdline->key);
-    storeAppendPrintf(sentry, "number active: %d of %d (%d shutting down)\n",
-                      hlp->childs.n_active, hlp->childs.n_max, (hlp->childs.n_running - hlp->childs.n_active) );
-    storeAppendPrintf(sentry, "requests sent: %d\n",
-                      hlp->stats.requests);
-    storeAppendPrintf(sentry, "replies received: %d\n",
-                      hlp->stats.replies);
-    storeAppendPrintf(sentry, "requests timedout: %d\n",
-                      hlp->stats.timedout);
-    storeAppendPrintf(sentry, "queue length: %d\n",
-                      hlp->stats.queue_size);
-    storeAppendPrintf(sentry, "avg service time: %d msec\n",
-                      hlp->stats.avg_svc_time);
-    storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "%7s\t%7s\t%7s\t%11s\t%11s\t%11s\t%s\t%7s\t%7s\t%7s\n",
+    if (label)
+        p->appendf("%s:\n", label);
+
+    p->appendf("  program: %s\n", cmdline->key);
+    p->appendf("  number active: %d of %d (%d shutting down)\n", childs.n_active, childs.n_max, (childs.n_running - childs.n_active));
+    p->appendf("  requests sent: %d\n", stats.requests);
+    p->appendf("  replies received: %d\n", stats.replies);
+    p->appendf("  requests timedout: %d\n", stats.timedout);
+    p->appendf("  queue length: %d\n", stats.queue_size);
+    p->appendf("  avg service time: %d msec\n", stats.avg_svc_time);
+    p->append("\n",1);
+    p->appendf("%7s\t%7s\t%7s\t%11s\t%11s\t%11s\t%6s\t%7s\t%7s\t%7s\n",
                       "ID #",
                       "FD",
                       "PID",
