     return memset(dst, val, sz);
 }
 
+bool
+IamWorkerProcess()
+{
+    fprintf(stderr, "Not implemented");
+    return true;
+}
+
+bool
+IamDiskProcess()
+{
+    fprintf(stderr, "Not implemented");
+    return false;
+}
+
+bool
+IamMasterProcess()
+{
+    fprintf(stderr, "Not implemented");
+    return false;
+}
+
+bool
+UsingSmp()
+{
+    fprintf(stderr, "Not implemented");
+    return false;
+}
+
 void
 logsFlush(void)
 {
