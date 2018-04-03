 int httpHeaderParseInt(const char *start, int *val);
 void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
 
-const char *getStringPrefix(const char *str, const char *end);
+const char *getStringPrefix(const char *str, size_t len);
 
 void httpHdrMangleList(HttpHeader *, HttpRequest *, int req_or_rep);
 
