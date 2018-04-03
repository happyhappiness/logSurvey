     else
         Enqueue(this, r);
 
-    if (!queueFull()) {
-        full_time = 0;
-    } else if (!full_time) {
-        debugs(84, 3, id_name << " queue became full");
-        full_time = squid_curtime;
+    syncQueueStats();
+}
+
+/// handles helperSubmit() and helperStatefulSubmit() failures
+static void
+SubmissionFailure(helper *hlp, HLPCB *callback, void *data)
+{
+    auto result = Helper::Error;
+    if (!hlp) {
+        debugs(84, 3, "no helper");
+        result = Helper::Unknown;
     }
+    // else pretend the helper has responded with ERR
+
+    callback(data, Helper::Reply(result));
 }
 
 void
 helperSubmit(helper * hlp, const char *buf, HLPCB * callback, void *data)
 {
-    if (hlp == NULL) {
-        debugs(84, 3, "helperSubmit: hlp == NULL");
-        Helper::Reply const nilReply(Helper::Unknown);
-        callback(data, nilReply);
-        return;
-    }
-    hlp->prepSubmit();
-    hlp->submit(buf, callback, data);
+    if (!hlp || !hlp->trySubmit(buf, callback, data))
+        SubmissionFailure(hlp, callback, data);
 }
 
+/// whether queuing an additional request would overload the helper
 bool
 helper::queueFull() const {
+    return stats.queue_size >= static_cast<int>(childs.queue_size);
+}
+
+bool
+helper::overloaded() const {
     return stats.queue_size > static_cast<int>(childs.queue_size);
 }
 
-/// prepares the helper for request submission via trySubmit() or helperSubmit()
-/// currently maintains full_time and kills Squid if the helper remains full for too long
+/// synchronizes queue-dependent measurements with the current queue state
 void
-helper::prepSubmit()
+helper::syncQueueStats()
 {
-    if (!queueFull())
-        full_time = 0;
-    else if (!full_time) // may happen here if reconfigure decreases capacity
-        full_time = squid_curtime;
-    else if (squid_curtime - full_time > 180)
-        fatalf("Too many queued %s requests", id_name);
+    if (overloaded()) {
+        if (overloadStart) {
+            debugs(84, 5, id_name << " still overloaded; dropped " << droppedRequests);
+        } else {
+            overloadStart = squid_curtime;
+            debugs(84, 3, id_name << " became overloaded");
+        }
+    } else {
+        if (overloadStart) {
+            debugs(84, 5, id_name << " is no longer overloaded");
+            if (droppedRequests) {
+                debugs(84, DBG_IMPORTANT, "helper " << id_name <<
+                       " is no longer overloaded after dropping " << droppedRequests <<
+                       " requests in " << (squid_curtime - overloadStart) << " seconds");
+                droppedRequests = 0;
+            }
+            overloadStart = 0;
+        }
+    }
 }
 
+/// prepares the helper for request submission
+/// returns true if and only if the submission should proceed
+/// may kill Squid if the helper remains overloaded for too long
 bool
-helper::trySubmit(const char *buf, HLPCB * callback, void *data)
+helper::prepSubmit()
 {
-    prepSubmit();
+    // re-sync for the configuration may have changed since the last submission
+    syncQueueStats();
+
+    // Nothing special to do if the new request does not overload (i.e., the
+    // queue is not even full yet) or only _starts_ overloading this helper
+    // (i.e., the queue is currently at its limit).
+    if (!overloaded())
+        return true;
 
-    if (queueFull()) {
-        debugs(84, DBG_IMPORTANT, id_name << " drops request due to a full queue");
-        return false; // request was ignored
+    if (squid_curtime - overloadStart <= 180)
+        return true; // also OK: overload has not persisted long enough to panic
+
+    if (childs.onPersistentOverload == Helper::ChildConfig::actDie)
+        fatalf("Too many queued %s requests; see on-persistent-overload.", id_name);
+
+    if (!droppedRequests) {
+        debugs(84, DBG_IMPORTANT, "WARNING: dropping requests to overloaded " <<
+               id_name << " helper configured with on-persistent-overload=err");
     }
+    ++droppedRequests;
+    debugs(84, 3, "failed to send " << droppedRequests << " helper requests to " << id_name);
+    return false;
+}
+
+bool
+helper::trySubmit(const char *buf, HLPCB * callback, void *data)
+{
+    if (!prepSubmit())
+        return false; // request was dropped
 
     submit(buf, callback, data); // will send or queue
     return true; // request submitted or queued
