 extern int httpHeaderParseInt(const char *start, int *val);
 extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
 
+extern const char *getStringPrefix(const char *str, const char *end);
+
+extern void httpHdrMangleList(HttpHeader *, HttpRequest *, int req_or_rep);
+
 #endif
