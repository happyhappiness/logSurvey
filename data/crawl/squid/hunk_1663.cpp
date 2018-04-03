 {
 
 public:
-    SignalEngine(EventLoop &evtLoop) : loop(evtLoop) {}
     virtual int checkEvents(int timeout);
 
 private:
-    static void StopEventLoop(void * data) {
-        static_cast<SignalEngine *>(data)->loop.stop();
+    static void StopEventLoop(void *) {
+        if (EventLoop::Running)
+            EventLoop::Running->stop();
     }
 
     void doShutdown(time_t wait);
-
-    EventLoop &loop;
 };
 
 int
