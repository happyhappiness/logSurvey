		die("transport '%s' not allowed", type);
}

struct transport *transport_get(struct remote *remote, const char *url)
{
	const char *helper;
