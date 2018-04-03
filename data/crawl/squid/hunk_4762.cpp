 
 #include "EventLoop.h"
 
-EventLoop::EventLoop() : errcount(0), last_loop(false), timeService(NULL)
+EventLoop::EventLoop() : errcount(0), last_loop(false), timeService(NULL),
+        primaryEngine(NULL)
 {}
 
+void
+EventLoop::checkEngine(AsyncEngine * engine, bool const primary)
+{
+    int requested_delay;
+
+    if (!primary)
+        requested_delay = engine->checkEvents(0);
+    else
+        requested_delay = engine->checkEvents(loop_delay);
+
+    if (requested_delay < 0)
+        switch (requested_delay) {
+
+        case AsyncEngine::EVENT_IDLE:
+            debugs(1, 9, "Engine " << engine << " is idle.");
+            break;
+
+        case AsyncEngine::EVENT_ERROR:
+            runOnceResult = false;
+            error = true;
+            break;
+
+        default:
+            fatal_dump("unknown AsyncEngine result");
+        }
+    else {
+        /* not idle or error */
+        runOnceResult = false;
+
+        if (requested_delay < loop_delay)
+            loop_delay = requested_delay;
+    }
+}
+
 void
 EventLoop::prepareToRun()
 {
