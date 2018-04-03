 
     buf.append(" [", 2);
     if (stopReason != NULL) {
-        buf.Printf("Stopped, reason:");
-        buf.Printf("%s",stopReason);
+        buf.appendf("Stopped, reason:%s", stopReason);
     }
-    buf.Printf(" %s%u]", id.Prefix, id.value);
+    buf.appendf(" %s%u]", id.Prefix, id.value);
     buf.terminate();
 
     return buf.content();
