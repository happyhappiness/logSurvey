     dispatchers.push_back(dispatcher);
 }
 
+void
+EventLoop::registerEngine(AsyncEngine *engine)
+{
+    engines.push_back(engine);
+}
+
 void
 EventLoop::run()
 {
     prepareToRun();
 
-    while (!last_loop)
-        runOnce();
+    while (!runOnce())
+
+        ;
 }
 
-void
+bool
 EventLoop::runOnce()
 {
-    int loop_delay = EventScheduler::GetInstance()->checkEvents();
+    bool result = true;
+    bool error = false;
+    int loop_delay = 10; /* 10 ms default delay */
+
+    for (engine_vector::iterator i = engines.begin();
+            i != engines.end(); ++i) {
+        int requested_delay;
+        /* special case the last engine */
+
+        if (i - engines.end() != -1)
+            requested_delay = (*i)->checkEvents(0);
+        else /* last engine gets the delay */
+            requested_delay = (*i)->checkEvents(loop_delay);
+
+        if (requested_delay < 0)
+            switch (requested_delay) {
+
+            case AsyncEngine::EVENT_IDLE:
+                debugs(1, 9, "Engine " << *i << " is idle.");
+                break;
+
+            case AsyncEngine::EVENT_ERROR:
+                result = false;
+                error = true;
+                break;
+
+            default:
+                fatal_dump("unknown AsyncEngine result");
+            }
+        else if (requested_delay < loop_delay) {
+            loop_delay = requested_delay;
+            result = false;
+        }
+    }
+
+    if (timeService != NULL)
+        timeService->tick();
 
     for (dispatcher_vector::iterator i = dispatchers.begin();
             i != dispatchers.end(); ++i)
-        (*i)->dispatch();
-
-    if (loop_delay < 0)
-        loop_delay = 0;
-
-    switch (comm_select(loop_delay)) {
-
-    case COMM_OK:
-        errcount = 0;	/* reset if successful */
-        break;
-
-    case COMM_IDLE:
-        /* TODO: rather than busy loop, if everything has returned IDLE we should
-         * wait for a reasonable timeout period, - if everything returned IDLE
-         * then not only is there no work to do, there is no work coming in -
-         * all the comm loops have no fds registered, and  all the other 
-         * async engines have no work active or pending.
-         * ... perhaps we can have a query method to say 'when could there be 
-         * work' - i.e. the event dispatcher can return the next event in its
-         * queue, and everything else can return -1.
-         */
-        errcount = 0;
-        break;
+        if ((*i)->dispatch())
+            result = false;
 
-    case COMM_ERROR:
-        errcount++;
+    if (error) {
+        ++errcount;
         debugs(1, 0, "Select loop Error. Retry " << errcount);
+    } else
+        errcount = 0;
 
-        if (errcount == 10)
-            fatal_dump("Select Loop failed 10 times.!");
-
-        break;
-
-    case COMM_TIMEOUT:
-        break;
-
-    case COMM_SHUTDOWN:
-        stop();
+    if (errcount == 10)
+        return true;
 
-        break;
+    if (last_loop)
+        return true;
 
-    default:
-        fatal_dump("MAIN: Internal error -- this should never happen.");
+    return result;
+}
 
-        break;
-    }
+void
+EventLoop::setTimeService(TimeEngine *engine)
+{
+    timeService = engine;
 }
 
 void
