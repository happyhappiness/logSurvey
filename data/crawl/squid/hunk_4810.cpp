         F->timeout = squid_curtime + timeout;
 }
 
+
+static void commIncomingStats(StoreEntry * sentry);
+
+void
+commEPollRegisterWithCacheManager(CacheManager& manager)
+{
+    manager.registerAction("comm_epoll_incoming",
+                           "comm_incoming() stats",
+                           commIncomingStats, 0, 1);
+}
+
+static void
+commIncomingStats(StoreEntry * sentry)
+{
+    StatCounters *f = &statCounter;
+    storeAppendPrintf(sentry, "Total number of epoll(2) loops: %d\n", statCounter.select_loops);
+    storeAppendPrintf(sentry, "Histogram of returned filedescriptors\n");
+    statHistDump(&f->select_fds_hist, sentry, statHistIntDumper);
+}
+
 /*
+ * comm_select
  * Check all connections for new connections and input data that is to be
  * processed. Also check for connections with data queued and whether we can
  * write it out.
- */
-
-/*
- * comm_select
  *
  * Called to do the new-style IO, courtesy of of squid (like most of this
  * new IO code). This routine handles the stuff we've hidden in
