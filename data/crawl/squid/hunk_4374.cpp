     return true; // so that it is safe for kids to use
 }
 
-bool AsyncJob::callStart(const char *method)
+bool AsyncJob::canBeCalled(AsyncCall &call) const
 {
-    debugs(93, 5, typeName << "::" << method << " called" << status());
-
-    if (inCall) {
-        // this may happen when we have bugs or when arguably buggy
-        // comm interface calls us while we are closing the connection
-        debugs(93, 5, HERE << typeName << "::" << inCall <<
-               " is in progress; " << typeName << "::" << method <<
-               " cancels reentry.");
-        return false;
+    if (inCall != NULL) {
+        // This may happen when we have bugs or some module is not calling
+        // us asynchronously (comm used to do that).
+        debugs(93, 5, HERE << inCall << " is in progress; " << 
+            call << " canot reenter the job.");
+        return call.cancel("reentrant job call");
     }
 
-    inCall = method;
     return true;
 }
 
+void AsyncJob::callStart(AsyncCall &call)
+{
+    // we must be called asynchronously and hence, the caller must lock us
+    Must(cbdataReferenceValid(toCbdata()));
+
+    Must(!inCall); // see AsyncJob::canBeCalled
+
+    inCall = &call; // XXX: ugly, but safe if callStart/callEnd,Ex are paired
+    debugs(inCall->debugSection, inCall->debugLevel,
+        typeName << " status in:" << status());
+}
+
 void AsyncJob::callException(const TextException &e)
 {
-    debugs(93, 3, typeName << "::" << inCall << " caught an exception: " <<
-           e.message << ' ' << status());
+    // we must be called asynchronously and hence, the caller must lock us
+    Must(cbdataReferenceValid(toCbdata()));
 
     mustStop("exception");
 }
 
 void AsyncJob::callEnd()
 {
     if (done()) {
-        debugs(93, 5, typeName << "::" << inCall << " ends job " <<
-            status());
+        debugs(93, 5, *inCall << " ends job" << status());
 
-        const char *inCallSaved = inCall;
-        const char *typeNameSaved = typeName;
+        AsyncCall::Pointer inCallSaved = inCall;
         void *thisSaved = this;
 
         swanSong();
 
-        void *cbdata = this;
         delete this; // this is the only place where the object is deleted
-        cbdataReferenceDone(cbdata); // locked by AsyncStart
 
         // careful: this object does not exist any more
-        debugs(93, 6, HERE << typeNameSaved << "::" << inCallSaved <<
-            " ended " << thisSaved);
+        debugs(93, 6, HERE << *inCallSaved << " ended " << thisSaved);
         return;
     }
 
-    debugs(93, 6, typeName << "::" << inCall << " ended" << status());
+    debugs(inCall->debugSection, inCall->debugLevel,
+        typeName << " status out:" << status());
     inCall = NULL;
 }
 
+// returns a temporary string depicting transaction status, for debugging
+const char *AsyncJob::status() const
+{
+    static MemBuf buf;
+    buf.reset();
+
+    buf.append(" [", 2);
+    if (stopReason != NULL){
+        buf.Printf("Stopped, reason:");
+	buf.Printf(stopReason);
+    }
+    buf.Printf(" job%d]", id);
+    buf.terminate();
+
+    return buf.content();
+}
+
+
+/* JobDialer */
+
+JobDialer::JobDialer(AsyncJob *aJob): job(aJob), lock(NULL)
+{
+    lock = cbdataReference(job->toCbdata());
+}
+
+JobDialer::JobDialer(const JobDialer &d): CallDialer(d),
+    job(d.job), lock(d.lock)
+{
+    cbdataReference(lock);
+}
+
+JobDialer::~JobDialer(){
+    cbdataReferenceDone(lock);
+}
+
+
+bool
+JobDialer::canDial(AsyncCall &call)
+{
+    if (!cbdataReferenceValid(lock))
+        return call.cancel("job is gone");
+
+    return job->canBeCalled(call);
+}
+
+void
+JobDialer::dial(AsyncCall &call) 
+{
+    assert(cbdataReferenceValid(lock)); // canDial() checks for this
+
+    job->callStart(call);
+
+    try {
+        doDial();
+	}
+    catch (const TextException &e) {
+        debugs(call.debugSection, 3,
+            HERE << call.name << " threw exception: " << e.message);
+        job->callException(e);
+    }
+
+    job->callEnd(); // may delete job
+}
