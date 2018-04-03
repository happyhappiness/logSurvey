     mustStop("ICAP service connection externally closed");
 }
 
-bool ICAPXaction::done() const
+void ICAPXaction::callEnd()
 {
-    // stopReason, set in mustStop(), overwrites all other conditions
-    return stopReason != NULL || doneAll();
+    if (doneWithIo()) {
+        debugs(93, 5, HERE << typeName << " done with I/O" << status());
+        closeConnection();
+    }
+    ICAPInitiate::callEnd(); // may destroy us
 }
 
 bool ICAPXaction::doneAll() const
 {
-    return !connector && !reader && !writer;
+    return !connector && !reader && !writer && ICAPInitiate::doneAll();
 }
 
 void ICAPXaction::updateTimeout() {
