     /* TODO: stop requiring the singleton here */
     mainLoop.registerDispatcher(EventDispatcher::GetInstance());
 
-    for (;;)
-    {
-        /* Attempt any pending storedir IO
-        * Note: the storedir is roughly a reactor of its own.
-        */
-        Store::Root().callback();
+    /* TODO: stop requiring the singleton here */
+    mainLoop.registerEngine(EventScheduler::GetInstance());
 
-        comm_calliocallback();
+    StoreRootEngine store_engine;
 
-        /* and again to deal with indirectly queued events
-         * resulting from the first call. These are usually
-         * callbacks and should be dealt with immediately.
-         */
+    mainLoop.registerEngine(&store_engine);
 
-        if (comm_iocallbackpending())
-            comm_calliocallback();
+    CommDispatcher comm_dispatcher;
 
-        mainLoop.runOnce();
-    }
+    mainLoop.registerDispatcher(&comm_dispatcher);
+
+    CommSelectEngine comm_engine;
+
+    /* must be last - its the only engine that implements timeouts properly
+     * at the moment.
+     */
+    mainLoop.registerEngine(&comm_engine);
+
+    /* use the standard time service */
+    TimeEngine time_engine;
+
+    mainLoop.setTimeService(&time_engine);
+
+    mainLoop.run();
+
+    if (mainLoop.errcount == 10)
+        fatal_dump("Event loop exited with failure.");
+
+    /* shutdown squid now */
+    SquidShutdown();
 
     /* NOTREACHED */
     return 0;
