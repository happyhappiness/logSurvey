extern int httpHeaderParseSize(const char *start, ssize_t * sz);
extern int httpHeaderReset(HttpHeader * hdr);
#if STDC_HEADERS
extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...);
#else
extern void httpHeaderPutStrf();
#endif
