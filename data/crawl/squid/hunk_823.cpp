 void Adaptation::Icap::Xaction::fillPendingStatus(MemBuf &buf) const
 {
     if (haveConnection()) {
-        buf.Printf("FD %d", connection->fd);
+        buf.appendf("FD %d", connection->fd);
 
         if (writer != NULL)
             buf.append("w", 1);
