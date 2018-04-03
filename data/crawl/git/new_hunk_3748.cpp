
void http_error(const char *url)
{
	error("unable to access '%s': %s", url, curl_errorstr);
}

int http_fetch_ref(const char *base, struct ref *ref)