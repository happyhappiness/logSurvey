	return strchr(url, ':') - url;
}

struct transport *transport_get(struct remote *remote, const char *url)
{
	const char *helper;
