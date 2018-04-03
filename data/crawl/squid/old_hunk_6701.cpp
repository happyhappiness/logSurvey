extern void ipcache_restart(void);
extern int ipcacheUnregister(const char *name, void *data);

extern char *mime_get_header(const char *mime, const char *header);
extern char *mime_headers_end(const char *mime);
extern int mk_mime_hdr(char *result, const char *type, int size, time_t ttl, time_t lmt);
