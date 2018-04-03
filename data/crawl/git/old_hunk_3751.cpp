int http_get_strbuf(const char *url, struct strbuf *content_type, struct strbuf *result, int options);

/*
 * Prints an error message using error() containing url and curl_errorstr,
 * and returns ret.
 */
int http_error(const char *url, int ret);

extern int http_fetch_ref(const char *base, struct ref *ref);

