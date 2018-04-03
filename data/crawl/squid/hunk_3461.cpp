 
 #if USE_DNSSERVERS
 
-    if (Config.dnsChildren < 1)
+    if (Config.dnsChildren.n_max < 1)
         fatal("No dnsservers allocated");
 
 #endif
 
     if (Config.Program.redirect) {
-        if (Config.redirectChildren < 1) {
-            Config.redirectChildren = 0;
+        if (Config.redirectChildren.n_max < 1) {
+            Config.redirectChildren.n_max = 0;
             wordlistDestroy(&Config.Program.redirect);
         }
     }
