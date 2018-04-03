 void ICAPXaction::fillPendingStatus(MemBuf &buf) const
 {
     if (connection >= 0) {
-        buf.Printf("Comm(%d", connection);
+        buf.Printf("FD %d", connection);
 
         if (writer)
             buf.append("w", 1);
 
         if (reader)
             buf.append("r", 1);
 
-        buf.append(")", 1);
+        buf.append(";", 1);
     }
 }
 
