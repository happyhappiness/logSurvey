 
 void Adaptation::Icap::ModXact::openChunk(MemBuf &buf, size_t chunkSize, bool ieof)
 {
-    buf.Printf((ieof ? "%x; ieof\r\n" : "%x\r\n"), (int) chunkSize);
+    buf.appendf((ieof ? "%x; ieof\r\n" : "%x\r\n"), (int) chunkSize);
 }
 
 void Adaptation::Icap::ModXact::closeChunk(MemBuf &buf)
