 }
 #endif
 
+#if XMALLOC_COUNT && !HAVE_MALLOCBLKSIZE
+int mallocblksize(p)
+     void *p;
+{
+    B = (((int) p) >> 4) & 0xFF;
+    for (I = 0; I < DBG_ARRY_SZ; I++) {
+	if (malloc_ptrs[B][I] == p)
+	    return malloc_size[B][I];
+    }
+    return 0;
+}
+#endif
+
 #ifdef XMALLOC_COUNT
 static void xmalloc_count(p, sign)
-	void *p;
-	int sign;
+     void *p;
+     int sign;
 {
-	size_t sz;
-	static size_t total = 0;
-	int memoryAccounted();
-	int mallinfoTotal();
-	sz = mallocblksize(p) * sign;
-	total += sz;
-	fprintf(stderr, "xmalloc_count=%9d  accounted=%9d  mallinfo=%9d\n",
-		(int) total,
-		memoryAccounted(),
-		mallinfoTotal());
+    size_t sz;
+    static size_t total = 0;
+    int memoryAccounted();
+    int mallinfoTotal();
+    sz = mallocblksize(p) * sign;
+    total += sz;
+    fprintf(stderr, "xmalloc_count=%9d  accounted=%9d  mallinfo=%9d\n",
+	(int) total,
+	memoryAccounted(),
+	mallinfoTotal());
 }
 #endif /* XMALLOC_COUNT */
 
