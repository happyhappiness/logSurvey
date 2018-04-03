     }
 
     x = read(fs->fd, buf, readlen);
-    DEBUG(2)
-    fprintf(stderr, "%d READ %d,%d,%"PRId64" ret %d\n", (int) mypid,
-            fs->fd, readlen, (int64_t)r->offset, x);
+    DEBUG(2) {
+        fprintf(stderr, "%d READ %d,%d,%"PRId64" ret %d\n", (int) mypid,
+                fs->fd, readlen, (int64_t)r->offset, x);
+    }
 
     if (x < 0) {
         DEBUG(1) {
