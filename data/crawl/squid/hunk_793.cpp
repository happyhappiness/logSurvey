     // id and stop reason reporting duplication.
     buf.append(" [", 2);
     if (stopReason != NULL) {
-        buf.Printf("Stopped, reason:");
-        buf.Printf("%s",stopReason);
+        buf.append("Stopped, reason:", 16);
+        buf.appendf("%s",stopReason);
     }
     if (serverConn != NULL)
-        buf.Printf(" FD %d", serverConn->fd);
-    buf.Printf(" %s%u]", id.Prefix, id.value);
+        buf.appendf(" FD %d", serverConn->fd);
+    buf.appendf(" %s%u]", id.Prefix, id.value);
     buf.terminate();
 
     return buf.content();