 */
int http_get_strbuf(const char *url, struct strbuf *content_type, struct strbuf *result, int options);

extern int http_fetch_ref(const char *base, struct ref *ref);

/* Helpers for fetching packs */