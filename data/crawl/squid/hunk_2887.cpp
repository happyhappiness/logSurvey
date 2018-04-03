 {
     static MemBuf buf;
     buf.reset();
-    buf.Printf(" [FD %d, requestId %u]", fd, requestId);
+    buf.Printf(" [FD %d, requestId %u]", clientConnection->fd, requestId);
     buf.terminate();
     return buf.content();
 }
