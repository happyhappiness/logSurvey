     write(tempBuffer);
 }
 
+void
+StoreEntry::vappendf(const char *fmt, va_list vargs)
+{
+    LOCAL_ARRAY(char, buf, 4096);
+    *buf = 0;
+    int x;
+
+    errno = 0;
+    if ((x = vsnprintf(buf, sizeof(buf), fmt, vargs)) < 0) {
+        fatalf( xstrerror(errno));
+        return;
+    }
+
+    if (x < sizeof(buf)) {
+        append(buf, x);
+        return;
+    }
+
+    // okay, do it the slow way.
+    char *buf2 = new char[x+1];
+    int y = vsnprintf(buf2, x+1, fmt, vargs);
+    assert(y >= 0 && y == x);
+    append(buf2, y);
+    delete[] buf2;
+}
+
+// deprecated. use StoreEntry::appendf() instead.
 void
 storeAppendPrintf(StoreEntry * e, const char *fmt,...)
 {
     va_list args;
     va_start(args, fmt);
-
-    storeAppendVPrintf(e, fmt, args);
+    e->vappendf(fmt, args);
     va_end(args);
 }
 
-/* used be storeAppendPrintf and Packer */
+// deprecated. use StoreEntry::appendf() instead.
 void
 storeAppendVPrintf(StoreEntry * e, const char *fmt, va_list vargs)
 {
-    LOCAL_ARRAY(char, buf, 4096);
-    buf[0] = '\0';
-    vsnprintf(buf, 4096, fmt, vargs);
-    e->append(buf, strlen(buf));
+    e->vappendf(fmt, vargs);
 }
 
 struct _store_check_cachable_hist {
