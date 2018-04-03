 extern const char *getStringPrefix(const char *str, const char *end);
 extern int httpHeaderParseInt(const char *start, int *val);
 extern int httpHeaderParseSize(const char *start, size_t * sz);
+#ifdef __STDC__
+extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt, ...);
+#else
+extern void httpHeaderPutStrf()
+#endif
 
 /* Http Header */
 extern void httpHeaderInitModule();
 extern void httpHeaderCleanModule();
 /* init/clean */
-extern void httpHeaderInit(HttpHeader * hdr);
+extern void httpHeaderInit(HttpHeader * hdr, http_hdr_owner_type owner);
 extern void httpHeaderClean(HttpHeader * hdr);
-/* update */
-extern void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh);
+/* append/update */
+extern void httpHeaderAppend(HttpHeader * dest, const HttpHeader * src);
+extern void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh, const HttpHeaderMask *denied_mask);
 /* parse/pack */
 extern int httpHeaderParse(HttpHeader * hdr, const char *header_start, const char *header_end);
 extern void httpHeaderPackInto(const HttpHeader * hdr, Packer * p);
