     return commEof;
 }
 
+bool ICAPXaction::doneWriting() const
+{
+    return !writer;
+}
+
+bool ICAPXaction::doneWithIo() const
+{
+    return connection >= 0 && // or we could still be waiting to open it
+        !connector && !reader && !writer && // fast checks, some redundant
+        doneReading() && doneWriting();
+}
+
 void ICAPXaction::mustStop(const char *aReason)
 {
     Must(inCall); // otherwise nobody will call doStop()
-    Must(!stopReason);
     Must(aReason);
-    stopReason = aReason;
-    debugs(93, 5, typeName << " will stop, reason: " << stopReason);
+    if (!stopReason) {
+        stopReason = aReason;
+        debugs(93, 5, typeName << " will stop, reason: " << stopReason);
+    } else {
+        debugs(93, 5, typeName << " will stop, another reason: " << aReason);
+    }
 }
 
 // internal cleanup
