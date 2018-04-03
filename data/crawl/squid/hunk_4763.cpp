 bool
 EventLoop::runOnce()
 {
-    bool result = true;
-    bool error = false;
-    int loop_delay = 10; /* 10 ms default delay */
+    runOnceResult = true;
+    error = false;
+    loop_delay = 10; /* 10 ms default delay */
 
     for (engine_vector::iterator i = engines.begin();
             i != engines.end(); ++i) {
-        int requested_delay;
-        /* special case the last engine */
-
-        if (i - engines.end() != -1)
-            requested_delay = (*i)->checkEvents(0);
-        else /* last engine gets the delay */
-            requested_delay = (*i)->checkEvents(loop_delay);
-
-        if (requested_delay < 0)
-            switch (requested_delay) {
-
-            case AsyncEngine::EVENT_IDLE:
-                debugs(1, 9, "Engine " << *i << " is idle.");
-                break;
-
-            case AsyncEngine::EVENT_ERROR:
-                result = false;
-                error = true;
-                break;
-
-            default:
-                fatal_dump("unknown AsyncEngine result");
-            }
-        else if (requested_delay < loop_delay) {
-            loop_delay = requested_delay;
-            result = false;
-        }
+        /* check the primary outside the loop */
+
+        if (*i == primaryEngine)
+            continue;
+
+        /* special case the last engine to be primary */
+        checkEngine(*i, primaryEngine == NULL && (i - engines.end() == -1));
     }
 
+    if (primaryEngine != NULL)
+        checkEngine(primaryEngine, true);
+
     if (timeService != NULL)
         timeService->tick();
 
     for (dispatcher_vector::iterator i = dispatchers.begin();
             i != dispatchers.end(); ++i)
         if ((*i)->dispatch())
-            result = false;
+            runOnceResult = false;
 
     if (error) {
         ++errcount;
