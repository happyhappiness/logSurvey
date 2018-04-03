 }
 
 
-/* vprintf for other printf()'s to use */
+/* vprintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
 void
 memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs)
 {
-    mb_size_t sz = 0;
+    int sz = 0;
     assert(mb && fmt);
     assert(mb->buf);
     assert(mb->freefunc);	/* not frozen */
