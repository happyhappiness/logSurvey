        to the right helper. squid must keep session state
     */
 
-    pipe(pkin);
-    pipe(pkout);
+    if (pipe(pkin) < 0) {
+        fprintf(stderr, "%s| %s: Could not assign streams for pkin\n", LogTime(), PROGRAM);
+        return 1;
+    }
+    if (pipe(pkout) < 0) {
+        fprintf(stderr, "%s| %s: Could not assign streams for pkout\n", LogTime(), PROGRAM);
+        return 1;
+    }
+
 
     if  (( fpid = vfork()) < 0 ) {
         fprintf(stderr, "%s| %s: Failed first fork\n", LogTime(), PROGRAM);
