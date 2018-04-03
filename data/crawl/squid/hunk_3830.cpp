     }
 }
 
-void ICAPXaction::fillDoneStatus(MemBuf &buf) const
+void Adaptation::Icap::Xaction::fillDoneStatus(MemBuf &buf) const
 {
     if (connection >= 0 && commEof)
         buf.Printf("Comm(%d)", connection);
