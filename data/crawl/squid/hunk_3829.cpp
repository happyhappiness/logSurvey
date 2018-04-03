     return buf.content();
 }
 
-void ICAPXaction::fillPendingStatus(MemBuf &buf) const
+void Adaptation::Icap::Xaction::fillPendingStatus(MemBuf &buf) const
 {
     if (connection >= 0) {
         buf.Printf("FD %d", connection);
