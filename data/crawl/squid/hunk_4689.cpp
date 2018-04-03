     static MemBuf buf;
     buf.reset();
 
-    buf.append("[", 1);
+    buf.append(" [", 2);
 
     fillPendingStatus(buf);
     buf.append("/", 1);
     fillDoneStatus(buf);
 
-    buf.append("]", 1);
+    buf.Printf(" icapx%d]", id);
 
     buf.terminate();
 
