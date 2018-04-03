 void MemBuf::reset() STUB
 int MemBuf::isNull() STUB_RETVAL(1)
 void MemBuf::Printf(const char *fmt,...) STUB
-void MemBuf::vPrintf(const char *fmt, va_list ap) STUB
+void MemBuf::vappendf(const char *fmt, va_list ap) STUB
 FREE *MemBuf::freeFunc() STUB_RETVAL(NULL)
 
 void memBufReport(MemBuf * mb) STUB