 void ICAPModXact::moveRequestChunk(MemBuf &buf, size_t chunkSize)
 {
     if (chunkSize > 0) {
-        openChunk(buf, chunkSize);
+        openChunk(buf, chunkSize, false);
         buf.append(claimContent(virginWriteClaim), chunkSize);
-        closeChunk(buf, false);
+        closeChunk(buf);
 
         virginWriteClaim.release(chunkSize);
         virginConsume();
     }
 
-    if (state.writing == State::writingPreview)
-        preview.wrote(chunkSize, state.doneReceiving); // even if wrote nothing
+    if (state.writing == State::writingPreview) {
+        // even if we are doneReceiving, we may not have written everything
+        const bool wroteEof = state.doneReceiving &&
+            claimSize(virginWriteClaim) <= 0;
+        preview.wrote(chunkSize, wroteEof); // even if wrote nothing
+    }
 }
 
 void ICAPModXact::addLastRequestChunk(MemBuf &buf)
 {
-    openChunk(buf, 0);
-    closeChunk(buf, state.writing == State::writingPreview && preview.ieof());
+    const bool ieof = state.writing == State::writingPreview && preview.ieof();
+    openChunk(buf, 0, ieof);
+    closeChunk(buf);
 }
 
-void ICAPModXact::openChunk(MemBuf &buf, size_t chunkSize)
+void ICAPModXact::openChunk(MemBuf &buf, size_t chunkSize, bool ieof)
 {
-    buf.Printf("%x\r\n", (int) chunkSize);
+    buf.Printf((ieof ? "%x; ieof\r\n" : "%x\r\n"), (int) chunkSize);
 }
 
-void ICAPModXact::closeChunk(MemBuf &buf, bool ieof)
+void ICAPModXact::closeChunk(MemBuf &buf)
 {
-    if (ieof)
-        buf.append("; ieof", 6);
-
     buf.append(ICAP::crlf, 2); // chunk-terminating CRLF
 }
 
