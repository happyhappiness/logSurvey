         return -errno;
     }
 
-    DEBUG(2)
-    fprintf(stderr, "%d UNLNK %s\n", (int) mypid, buf);
+    DEBUG(2) {
+        fprintf(stderr, "%d UNLNK %s\n", (int) mypid, buf);
+    }
     return 0;
 }
 
