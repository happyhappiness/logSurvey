     close(pkin[0]);
     close(pkout[1]);
 
-    pipe(pnin);
-    pipe(pnout);
+    if (pipe(pnin) < 0) {
+        fprintf(stderr, "%s| %s: Could not assign streams for pnin\n", LogTime(), PROGRAM);
+        return 1;
+    }
+    if (pipe(pnout) < 0) {
+        fprintf(stderr, "%s| %s: Could not assign streams for pnout\n", LogTime(), PROGRAM);
+        return 1;
+    }
 
     if  (( fpid = vfork()) < 0 ) {
         fprintf(stderr, "%s| %s: Failed second fork\n", LogTime(), PROGRAM);