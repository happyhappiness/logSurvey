             buf.append(" A?", 3);
     }
 
-    buf.Printf(" %s%u]", id.Prefix, id.value);
+    buf.appendf(" %s%u]", id.Prefix, id.value);
 
     buf.terminate();
 