  * vPrintf for other printf()'s to use; calls vsnprintf, extends buf if needed
  */
 void
-MemBuf::vPrintf(const char *fmt, va_list vargs) {
+MemBuf::vPrintf(const char *fmt, va_list vargs)
+{
 #ifdef VA_COPY
     va_list ap;
 #endif
