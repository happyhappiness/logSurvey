extern int httpHeaderReset(HttpHeader * hdr);
#if STDC_HEADERS
extern void
httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
#else
extern void httpHeaderPutStrf();
#endif
