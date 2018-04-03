 class HttpRequest;
 class HttpReply;
 
-
-/* Http Header Tools */
-class HttpHeaderFieldInfo;
-SQUIDCEXTERN HttpHeaderFieldInfo *httpHeaderBuildFieldsInfo(const HttpHeaderFieldAttrs * attrs, int count);
-SQUIDCEXTERN void httpHeaderDestroyFieldsInfo(HttpHeaderFieldInfo * info, int count);
-SQUIDCEXTERN http_hdr_type httpHeaderIdByName(const char *name, size_t name_len, const HttpHeaderFieldInfo * attrs, int end);
-SQUIDCEXTERN http_hdr_type httpHeaderIdByNameDef(const char *name, int name_len);
-SQUIDCEXTERN const char *httpHeaderNameById(int id);
-SQUIDCEXTERN int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
+/* TODO: move to StrList.h */
 SQUIDCEXTERN void strListAdd(String * str, const char *item, char del);
 SQUIDCEXTERN int strListIsMember(const String * str, const char *item, char del);
 SQUIDCEXTERN int strListIsSubstr(const String * list, const char *s, char del);
 SQUIDCEXTERN int strListGetItem(const String * str, char del, const char **item, int *ilen, const char **pos);
-SQUIDCEXTERN const char *getStringPrefix(const char *str, const char *end);
-SQUIDCEXTERN int httpHeaderParseInt(const char *start, int *val);
-SQUIDCEXTERN void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
+
+extern const char *getStringPrefix(const char *str, const char *end);
 
 
 