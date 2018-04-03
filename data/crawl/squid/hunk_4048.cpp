     buf.append(" [", 2);
     if (stopReason != NULL) {
         buf.Printf("Stopped, reason:");
-        buf.Printf(stopReason);
+        buf.Printf("%s",stopReason);
     }
     buf.Printf(" job%d]", id);
     buf.terminate();