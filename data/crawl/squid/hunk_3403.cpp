     if (notifying)
         buf.append(",notif", 6);
 
-    if (theSessionFailures > 0)
-        buf.Printf(",fail%d", theSessionFailures);
+    if (const int failures = theSessionFailures.remembered())
+        buf.Printf(",fail%d", failures);
 
     buf.append("]", 1);
     buf.terminate();
