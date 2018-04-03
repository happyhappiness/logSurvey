extern int httpHeaderParseInt(const char *start, int *val);
extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;

#endif
