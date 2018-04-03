     };
 };
 
-class SignalDispatcher : public CompletionDispatcher
+class SignalEngine: public AsyncEngine
 {
 
 public:
-    SignalDispatcher(EventLoop &loop) : loop(loop), events_dispatched(false) {}
-
-    void addEventLoop(EventLoop * loop);
-    virtual bool dispatch();
+    SignalEngine(EventLoop &loop) : loop(loop) {}
+    virtual int checkEvents(int timeout);
 
 private:
     static void StopEventLoop(void * data)
     {
-        static_cast<SignalDispatcher *>(data)->loop.stop();
+        static_cast<SignalEngine *>(data)->loop.stop();
     }
 
+    void doShutdown(time_t wait);
+
     EventLoop &loop;
-    bool events_dispatched;
 };
 
-bool
-SignalDispatcher::dispatch()
+int
+SignalEngine::checkEvents(int timeout)
 {
-    PROF_start(SignalDispatcher_dispatch);
+    PROF_start(SignalEngine_checkEvents);
 
     if (do_reconfigure) {
         mainReconfigure();
