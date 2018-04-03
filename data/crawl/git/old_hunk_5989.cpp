
#define missing_target(a) missing__target((a)->http_code, (a)->curl_result)

extern int http_fetch_ref(const char *base, struct ref *ref);

#endif /* HTTP_H */