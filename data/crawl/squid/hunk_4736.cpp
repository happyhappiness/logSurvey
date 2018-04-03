 
 bool ICAPXaction::done() const
 {
-    if (stopReason != NULL) { // mustStop() has been called
-        debugs(93,1,HERE << "ICAPXaction is done() because " << stopReason);
-        return true;
-    }
-
-    return doneAll();
+    // stopReason, set in mustStop(), overwrites all other conditions
+    return stopReason != NULL || doneAll();
 }
 
 bool ICAPXaction::doneAll() const
 {
     return !connector && !reader && !writer;
 }
 
+void ICAPXaction::updateTimeout() {
+    if (reader || writer) {
+        // restart the timeout before each I/O
+        // XXX: why does Config.Timeout lacks a write timeout?
+        commSetTimeout(connection, Config.Timeout.read,
+            &ICAPXaction_noteCommTimedout, this);
+    } else {
+        // clear timeout when there is no I/O
+        // Do we need a lifetime timeout?
+        commSetTimeout(connection, -1, NULL, NULL);
+    }
+}
+
 void ICAPXaction::scheduleRead()
 {
     Must(connection >= 0);
