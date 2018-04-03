         return 0;
     }
 
-    if (debug)
+    if (debug_enabled)
         fprintf(stderr, "%s| %s: Starting version %s\n", LogTime(), PROGRAM,
                 VERSION);
 
