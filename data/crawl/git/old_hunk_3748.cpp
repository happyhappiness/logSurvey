
void http_error(const char *url)
{
	error("%s while accessing %s", curl_errorstr, url);
}

int http_fetch_ref(const char *base, struct ref *ref)