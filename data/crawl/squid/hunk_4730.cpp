     return virginBody.size() < TheBackupLimit;
 }
 
-// returns a temporary string depicting transaction status, for debugging
 void ICAPModXact::fillPendingStatus(MemBuf &buf) const
 {
+    ICAPXaction::fillPendingStatus(buf);
+
     if (state.serviceWaiting)
         buf.append("U", 1);
 
+    if (!state.doneReceiving)
+        buf.append("R", 1);
+
+    if (!doneReading())
+        buf.append("r", 1);
+
     if (!state.doneWriting() && state.writing != State::writingInit)
         buf.Printf("w(%d)", state.writing);
 
