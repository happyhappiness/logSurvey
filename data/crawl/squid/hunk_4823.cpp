 }
 
 int commIsHalfClosed(int fd) {
-    if (fdc_table[fd].active != 1) {
-        fatal("foo");
-    }
+    assert (fdc_table[fd].active);
 
     return fdc_table[fd].half_closed;
 }