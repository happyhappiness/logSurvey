     return 0;
 }
 static void
-xmalloc_trace(void *p, int sign)
+xmalloc_show_trace(void *p, int sign)
 {
     int statMemoryAccounted();
     static size_t last_total = 0, last_accounted = 0, last_mallinfo = 0;
     struct mallinfo mp = mallinfo();
     size_t accounted = statMemoryAccounted();
     size_t mi = mp.uordblks + mp.usmblks + mp.hblkhd;
     size_t sz;
-    static size_t total = 0;
     sz = mallocblksize(p) * sign;
-    total += sz;
-    xmalloc_count += sign>0;
-    fprintf(stderr, "%c%8p size=%5d/%d acc=%5d/%d mallinfo=%5d/%d %s:%d %s",
-	sign>0 ? '+':'-',p,
-	(int) total - last_total, (int) total,
-	(int) accounted - last_accounted, (int) accounted,
-	(int) mi - last_mallinfo, (int) mi,
-	xmalloc_file, xmalloc_line, xmalloc_func);
-    if (sign<0)
-	fprintf(stderr," (%d %s:%d)\n",malloc_number(p),malloc_file_name(p),malloc_line_number(p));
-    else
-	fprintf(stderr," %d\n",xmalloc_count);
-    last_total = total;
+    xmalloc_total += sz;
+    xmalloc_count += sign > 0;
+    if (xmalloc_trace) {
+	fprintf(stderr, "%c%8p size=%5d/%d acc=%5d/%d mallinfo=%5d/%d %s:%d %s",
+	    sign > 0 ? '+' : '-', p,
+	    (int) xmalloc_total - last_total, (int) xmalloc_total,
+	    (int) accounted - last_accounted, (int) accounted,
+	    (int) mi - last_mallinfo, (int) mi,
+	    xmalloc_file, xmalloc_line, xmalloc_func);
+	if (sign < 0)
+	    fprintf(stderr, " (%d %s:%d)\n", malloc_number(p), malloc_file_name(p), malloc_line_number(p));
+	else
+	    fprintf(stderr, " %d\n", xmalloc_count);
+    }
+    last_total = xmalloc_total;
     last_accounted = accounted;
     last_mallinfo = mi;
 }
-
+short (*malloc_refs)[DBG_ARRY_SZ];
+char **xmalloc_leak_test;
+#define XMALLOC_LEAK_CHECKED (1<<15)
+#define XMALLOC_LEAK_ALIGN (4)
+static int
+xmalloc_scan_region(void *start, int size)
+{
+    int B, I;
+    char *ptr = start;
+    char *end = ptr + size - XMALLOC_LEAK_ALIGN;
+    int found = 0;
+    while (ptr <= end) {
+	void *p = *(void **) ptr;
+	if (p && p != start) {
+	    B = (((int) p) >> 4) & 0xFF;
+	    for (I = 0; I < DBG_ARRY_SZ; I++) {
+		if (malloc_ptrs[B][I] == p) {
+		    if (!malloc_refs[B][I])
+			found++;
+		    malloc_refs[B][I]++;
+		}
+	    }
+	}
+	ptr += XMALLOC_LEAK_ALIGN;
+    }
+    return found;
+}
+extern void _etext;
+void
+xmalloc_find_leaks(void)
+{
+    int B, I;
+    int found;
+    int leak_sum = 0;
+    fprintf(stderr, "Searching for memory references...\n");
+    malloc_refs = xcalloc(DBG_ARRY_BKTS, sizeof(*malloc_refs));
+    found = xmalloc_scan_region(&_etext, (void *) sbrk(0) - (void *) &_etext);
+    while (found) {
+	found = 0;
+	for (I = 0; I < DBG_ARRY_SZ && !found; I++) {
+	    for (B = 0; B < DBG_ARRY_BKTS; B++) {
+		if (malloc_refs[B][I] > 0) {
+		    malloc_refs[B][I] |= XMALLOC_LEAK_CHECKED;
+		    found += xmalloc_scan_region(malloc_ptrs[B][I],
+			malloc_size[B][I]);
+		}
+	    }
+	}
+    }
+    for (B = 0; B < DBG_ARRY_BKTS; B++) {
+	for (I = 0; I < DBG_ARRY_SZ; I++) {
+	    if (malloc_ptrs[B][I] && malloc_refs[B][I] == 0) {
+		/* Found a leak... */
+		fprintf(stderr, "Leak found: %p", malloc_ptrs[B][I]);
+		fprintf(stderr, " %s", malloc_file[B][I]);
+		fprintf(stderr, ":%d", malloc_line[B][I]);
+		fprintf(stderr, " size %d\n", malloc_size[B][I]);
+		fprintf(stderr, " allocation %d", malloc_count[B][I]);
+		leak_sum += malloc_size[B][I];
+	    }
+	}
+    }
+    if (leak_sum) {
+	fprintf(stderr, "Total leaked memory: %d\n", leak_sum);
+    } else {
+	fprintf(stderr, "No memory leaks detected\n");
+    }
+}
+void
+xmalloc_dump_map(void)
+{
+    int B, I;
+    fprintf(stderr, "----- Memory map ----\n");
+    for (B = 0; B < DBG_ARRY_BKTS; B++) {
+	for (I = 0; I < DBG_ARRY_SZ; I++) {
+	    if (malloc_ptrs[B][I]) {
+		printf("%p %s:%d size %d allocation %d references %d\n",
+		    malloc_ptrs[B][I], malloc_file[B][I], malloc_line[B][I],
+		    malloc_size[B][I], malloc_count[B][I],
+		    malloc_refs[B][I] & (XMALLOC_LEAK_CHECKED - 1));
+	    }
+	}
+    }
+    fprintf(stderr, "----------------------\n");
+}
 #endif /* XMALLOC_TRACE */
 
 /*
