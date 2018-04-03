     fprintf(stderr, "Not implemented");
     exit(1);
 }
+
+void*
+xmemset(void* dst, int val, size_t sz)
+{
+    assert(dst);
+    return memset(dst, val, sz);
+}
