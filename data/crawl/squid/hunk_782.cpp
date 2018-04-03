 void MemBuf::clean() STUB
 void MemBuf::reset() STUB
 int MemBuf::isNull() STUB_RETVAL(1)
-void MemBuf::Printf(const char *fmt,...) STUB
-void MemBuf::vPrintf(const char *fmt, va_list ap) STUB
 FREE *MemBuf::freeFunc() STUB_RETVAL(NULL)
+void MemBuf::append(const char *, int) STUB
+void MemBuf::vappendf(const char *fmt, va_list ap) STUB
 
 void memBufReport(MemBuf * mb) STUB
-void packerToMemInit(Packer * p, MemBuf * mb) STUB
 
