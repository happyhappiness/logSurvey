static int remote_exists(const char *path)
{
	char *url = xmalloc(strlen(repo->url) + strlen(path) + 1);
	int ret;

	sprintf(url, "%s%s", repo->url, path);

	switch (http_get_strbuf(url, NULL, 0)) {
	case HTTP_OK:
		ret = 1;
		break;
	case HTTP_MISSING_TARGET:
		ret = 0;
		break;
	case HTTP_ERROR:
		http_error(url, HTTP_ERROR);
	default:
		ret = -1;
	}
	free(url);
	return ret;
}