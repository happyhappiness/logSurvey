 void Adaptation::Icap::Xaction::fillDoneStatus(MemBuf &buf) const
 {
     if (haveConnection() && commEof)
-        buf.Printf("Comm(%d)", connection->fd);
+        buf.appendf("Comm(%d)", connection->fd);
 
     if (stopReason != NULL)
-        buf.Printf("Stopped");
+        buf.append("Stopped", 7);
 }
 
 bool Adaptation::Icap::Xaction::fillVirginHttpHeader(MemBuf &) const
