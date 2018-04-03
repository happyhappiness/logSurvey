     bool quoted;
 };
 
-extern int httpHeaderParseOffset(const char *start, int64_t * off);
+int httpHeaderParseOffset(const char *start, int64_t * off);
 
-class HttpHeaderFieldInfo;
-class String;
+HttpHeaderFieldInfo *httpHeaderBuildFieldsInfo(const HttpHeaderFieldAttrs * attrs, int count);
+void httpHeaderDestroyFieldsInfo(HttpHeaderFieldInfo * info, int count);
+http_hdr_type httpHeaderIdByName(const char *name, size_t name_len, const HttpHeaderFieldInfo * attrs, int end);
+http_hdr_type httpHeaderIdByNameDef(const char *name, int name_len);
+const char *httpHeaderNameById(int id);
+int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
+int httpHeaderParseInt(const char *start, int *val);
+void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
+
+const char *getStringPrefix(const char *str, const char *end);
 
-extern HttpHeaderFieldInfo *httpHeaderBuildFieldsInfo(const HttpHeaderFieldAttrs * attrs, int count);
-extern void httpHeaderDestroyFieldsInfo(HttpHeaderFieldInfo * info, int count);
-extern http_hdr_type httpHeaderIdByName(const char *name, size_t name_len, const HttpHeaderFieldInfo * attrs, int end);
-extern http_hdr_type httpHeaderIdByNameDef(const char *name, int name_len);
-extern const char *httpHeaderNameById(int id);
-extern int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
-extern int httpHeaderParseInt(const char *start, int *val);
-extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
+void httpHdrMangleList(HttpHeader *, HttpRequest *, int req_or_rep);
 
 #endif
