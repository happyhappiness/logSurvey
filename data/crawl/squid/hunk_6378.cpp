 extern int httpHeaderParseInt(const char *start, int *val);
 extern int httpHeaderParseSize(const char *start, size_t * sz);
 #ifdef __STDC__
-extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...);
+     extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt, ...);
 #else
-extern void 
-httpHeaderPutStrf()
+     extern void httpHeaderPutStrf()
 #endif
 
+
 /* Http Header */
      extern void httpHeaderInitModule();
      extern void httpHeaderCleanModule();
