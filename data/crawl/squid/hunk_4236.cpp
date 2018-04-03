 SQUIDCEXTERN const char *getStringPrefix(const char *str, const char *end);
 SQUIDCEXTERN int httpHeaderParseInt(const char *start, int *val);
 SQUIDCEXTERN int httpHeaderParseOffset(const char *start, int64_t * off);
-#if STDC_HEADERS
 SQUIDCEXTERN void
 httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
-#else
-SQUIDCEXTERN void httpHeaderPutStrf();
-#endif
 
 
 /* Http Header */
