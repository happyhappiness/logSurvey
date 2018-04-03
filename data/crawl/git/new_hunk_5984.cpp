{
	char *url;
	struct strbuf buffer = STRBUF_INIT;

	url = xmalloc(strlen(repo->url) + strlen(path) + 1);
	sprintf(url, "%s%s", repo->url, path);

	if (http_get_strbuf(url, &buffer, 0) != HTTP_OK)
		die("Couldn't get %s for remote symref\n%s", url,
		    curl_errorstr);
	free(url);

	free(*symref);