     }
 
     if (r->offset > -1 && r->offset != fs->offset) {
-        DEBUG(2)
-        fprintf(stderr, "seeking to %"PRId64"\n", (int64_t)r->offset);
+        DEBUG(2) {
+            fprintf(stderr, "seeking to %"PRId64"\n", (int64_t)r->offset);
+        }
 
         if (lseek(fs->fd, r->offset, SEEK_SET) < 0) {
             DEBUG(1) {
