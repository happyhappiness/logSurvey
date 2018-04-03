 extern void ipcache_restart(void);
 extern int ipcacheUnregister(const char *name, void *data);
 
+/* MemBuf */
+/* init with specific sizes */
+extern void memBufInit(MemBuf *mb, mb_size_t szInit, mb_size_t szMax);
+/* init with defaults */
+extern void memBufDefInit(MemBuf *mb);
+/* cleans the mb; last function to call if you do not give .buf away */
+extern void memBufClean(MemBuf *mb);
+/* calls memcpy, appends exactly size bytes, extends buffer if needed */
+extern void memBufAppend(MemBuf *mb, const char *buf, mb_size_t size);
+/* calls snprintf, extends buffer if needed */
+#ifdef __STDC__
+extern void memBufPrintf(MemBuf *mb, const char *fmt, ...);
+#else
+extern void memBufPrintf();
+#endif
+/* vprintf for other printf()'s to use */
+extern void memBufVPrintf(MemBuf *mb, const char *fmt, va_list ap);
+/* returns free() function to be used, _freezes_ the object! */
+extern FREE *memBufFreeFunc(MemBuf *mb);
+/* puts report on MemBuf _module_ usage into mb */
+extern void memBufReport(MemBuf *mb);
+
 extern char *mime_get_header(const char *mime, const char *header);
 extern char *mime_headers_end(const char *mime);
 extern int mk_mime_hdr(char *result, const char *type, int size, time_t ttl, time_t lmt);
