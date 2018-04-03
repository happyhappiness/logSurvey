     memset(&me, 0, sizeof(me));
     memset(&peer, 0, sizeof(peer));
 }
+
+bool
+CommDispatcher::dispatch() {
+    bool result = comm_iocallbackpending();
+    comm_calliocallback();
+    /* and again to deal with indirectly queued events
+     * resulting from the first call. These are usually
+     * callbacks and should be dealt with immediately.
+     */
+    comm_calliocallback();
+    return result;
+}
+
+int
+CommSelectEngine::checkEvents(int timeout) {
+    switch (comm_select(timeout)) {
+
+    case COMM_OK:
+
+    case COMM_TIMEOUT:
+        return 0;
+
+    case COMM_IDLE:
+
+    case COMM_SHUTDOWN:
+        return EVENT_IDLE;
+
+    case COMM_ERROR:
+        return EVENT_ERROR;
+
+    default:
+        fatal_dump("comm.cc: Internal error -- this should never happen.");
+        return EVENT_ERROR;
+    };
+}
