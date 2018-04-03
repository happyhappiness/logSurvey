 extern void httpHeaderMaskInit(HttpHeaderMask * mask, int value);
 extern void httpHeaderCalcMask(HttpHeaderMask * mask, const int *enums, int count);
 extern int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
-extern void httpHeaderAddContRange(HttpHeader * hdr, HttpHdrRangeSpec spec, size_t ent_len);
+extern void httpHeaderAddContRange(HttpHeader *, HttpHdrRangeSpec, ssize_t);
 extern void strListAdd(String * str, const char *item, char del);
 extern int strListIsMember(const String * str, const char *item, char del);
 extern int strListIsSubstr(const String * list, const char *s, char del);
 extern int strListGetItem(const String * str, char del, const char **item, int *ilen, const char **pos);
 extern const char *getStringPrefix(const char *str, const char *end);
 extern int httpHeaderParseInt(const char *start, int *val);
-extern int httpHeaderParseSize(const char *start, size_t * sz);
+extern int httpHeaderParseSize(const char *start, ssize_t * sz);
 extern int httpHeaderReset(HttpHeader * hdr);
 #if STDC_HEADERS
 extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...);
 #else
-extern void
-     httpHeaderPutStrf();
+extern void httpHeaderPutStrf();
 #endif
 
 
 /* Http Header */
-extern void httpHeaderInitModule();
-extern void httpHeaderCleanModule();
+extern void httpHeaderInitModule(void);
+extern void httpHeaderCleanModule(void);
 /* init/clean */
 extern void httpHeaderInit(HttpHeader * hdr, http_hdr_owner_type owner);
 extern void httpHeaderClean(HttpHeader * hdr);
