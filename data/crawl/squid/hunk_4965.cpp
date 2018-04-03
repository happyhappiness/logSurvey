 #include "MemBuf.cci"
 #endif
 
-/* MemBuf */
-/* init with specific sizes */
-SQUIDCEXTERN void memBufInit(MemBuf * mb, mb_size_t szInit, mb_size_t szMax);
-/* init with defaults */
-SQUIDCEXTERN void memBufDefInit(MemBuf * mb);
-/* cleans mb; last function to call if you do not give .buf away */
-SQUIDCEXTERN void memBufClean(MemBuf * mb);
-/* resets mb preserving (or initializing if needed) memory buffer */
-SQUIDCEXTERN void memBufReset(MemBuf * mb);
-/* unfirtunate hack to test if the buffer has been Init()ialized */
-SQUIDCEXTERN int memBufIsNull(MemBuf * mb);
-/* calls memcpy, appends exactly size bytes, extends buffer if needed */
-SQUIDCEXTERN void memBufAppend(MemBuf * mb, const char *buf, mb_size_t size);
-/* calls snprintf, extends buffer if needed */
-#if STDC_HEADERS
-SQUIDCEXTERN void
-memBufPrintf(MemBuf * mb, const char *fmt,...) PRINTF_FORMAT_ARG2;
-#else
-SQUIDCEXTERN void memBufPrintf();
-#endif
-/* vprintf for other printf()'s to use */
-SQUIDCEXTERN void memBufVPrintf(MemBuf * mb, const char *fmt, va_list ap);
 /* returns free() function to be used, _freezes_ the object! */
-SQUIDCEXTERN FREE *memBufFreeFunc(MemBuf * mb);
-/* puts report on MemBuf _module_ usage into mb */
 SQUIDCEXTERN void memBufReport(MemBuf * mb);
 
 #endif /* SQUID_MEM_H */
