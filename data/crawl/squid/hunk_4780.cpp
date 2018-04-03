 #include "test_access.c"
 #endif
 
+class SignalDispatcher : public CompletionDispatcher
+{
+
+public:
+    SignalDispatcher(EventLoop &loop) : loop(loop) {}
+
+    void addEventLoop(EventLoop * loop);
+    virtual void dispatch();
+
+private:
+    static void StopEventLoop(void * data)
+    {
+        static_cast<SignalDispatcher *>(data)->loop.stop();
+    }
+
+    EventLoop &loop;
+};
+
+void
+SignalDispatcher::dispatch()
+{
+    if (do_reconfigure) {
+        mainReconfigure();
+        do_reconfigure = 0;
+#if defined(_SQUID_MSWIN_) && defined(_DEBUG)
+
+    } else if (do_debug_trap) {
+        do_debug_trap = 0;
+        __asm int 3;
+#endif
+
+    } else if (do_rotate) {
+        mainRotate();
+        do_rotate = 0;
+    } else if (do_shutdown) {
+        time_t wait = do_shutdown > 0 ? (int) Config.shutdownLifetime : 0;
+        debug(1, 1) ("Preparing for shutdown after %d requests\n",
+                     statCounter.client_http.requests);
+        debug(1, 1) ("Waiting %d seconds for active connections to finish\n",
+                     (int) wait);
+        do_shutdown = 0;
+        shutting_down = 1;
+#if USE_WIN32_SERVICE
+
+        WIN32_svcstatusupdate(SERVICE_STOP_PENDING, (wait + 1) * 1000);
+#endif
+
+        serverConnectionsClose();
+        //eventAdd("SquidShutdown", StopEventLoop, this, (double) (wait + 1), 1, false);
+        eventAdd("SquidShutdown", SquidShutdown, NULL, (double) (wait + 1), 1, false);
+    }
+}
+
 static void
 usage(void)
 {
