             buf.append(" A.", 3);
     }
 
-    buf.Printf(" ecapx%d]", id);
+    buf.Printf(" %s%u]", id.Prefix, id.value);
 
     buf.terminate();
 
