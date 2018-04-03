     *space() = '\0';
 }
 
-void
-memBufAppend(MemBuf * mb, const char *buf, mb_size_t sz)
-{
-    assert(mb);
-    mb->append(buf, sz);
-}
-
 /* calls memBufVPrintf */
 #if STDC_HEADERS
 void
-memBufPrintf(MemBuf * mb, const char *fmt,...)
+MemBuf::Printf(const char *fmt,...)
 {
     va_list args;
     va_start(args, fmt);
 #else
 void
-memBufPrintf(va_alist)
+MemBuf::Printf(va_alist)
 va_dcl
 {
     va_list args;
-    MemBuf *mb = NULL;
-    const char *fmt = NULL;
     mb_size_t sz = 0;
     va_start(args);
-    mb = va_arg(args, MemBuf *);
-    fmt = va_arg(args, char *);
+    const char *fmt = va_arg(args, char *);
 #endif
 
-    memBufVPrintf(mb, fmt, args);
+    vPrintf(fmt, args);
     va_end(args);
 }
 
 
-/* vprintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
+/* vPrintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
 void
-memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs) {
+MemBuf::vPrintf(const char *fmt, va_list vargs) {
 #ifdef VA_COPY
     va_list ap;
 #endif
 
     int sz = 0;
-    assert(mb && fmt);
-    assert(mb->buf);
-    assert(!mb->stolen);	/* not frozen */
+    assert(fmt);
+    assert(buf);
+    assert(!stolen);	/* not frozen */
     /* assert in Grow should quit first, but we do not want to have a scary infinite loop */
 
-    while (mb->capacity <= mb->max_capacity) {
-        mb_size_t free_space = mb->capacity - mb->size;
+    while (capacity <= max_capacity) {
+        mb_size_t free_space = capacity - size;
         /* put as much as we can */
 
 #ifdef VA_COPY
