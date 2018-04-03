extern const char *getStringPrefix(const char *str, const char *end);
extern int httpHeaderParseInt(const char *start, int *val);
extern int httpHeaderParseSize(const char *start, size_t * sz);

/* Http Header */
extern void httpHeaderInitModule();
extern void httpHeaderCleanModule();
/* init/clean */
extern void httpHeaderInit(HttpHeader * hdr);
extern void httpHeaderClean(HttpHeader * hdr);
/* update */
extern void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh);
/* parse/pack */
extern int httpHeaderParse(HttpHeader * hdr, const char *header_start, const char *header_end);
extern void httpHeaderPackInto(const HttpHeader * hdr, Packer * p);
