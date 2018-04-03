	return strbuf_detach(&buf, NULL);
}

int http_fetch_ref(const char *base, struct ref *ref)
{
	char *url;
