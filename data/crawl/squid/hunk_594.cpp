 
 int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
 int httpHeaderParseInt(const char *start, int *val);
-void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
+void httpHeaderPutStrf(HttpHeader * hdr, Http::HdrType id, const char *fmt,...) PRINTF_FORMAT_ARG3;
 
 const char *getStringPrefix(const char *str, size_t len);
 
