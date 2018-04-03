 #endif
 
     if (NHttpSockets < 1)
-        fatal("Cannot open HTTP Port");
+        fatal("No HTTP or HTTPS ports configured"); // defaults prohibit this?
 }
 
 void