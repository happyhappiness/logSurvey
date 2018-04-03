     debugs(83, (alert.fatal() ? 2:3),
            "level " << static_cast<int>(alert.level) <<
            " description " << static_cast<int>(alert.description));
-    // we are currently ignoring Alert Protocol messages
+    if (alert.fatal())
+        done = "fatal Alert";
+    // else ignore the warning (at least for now)
 }
 
 void