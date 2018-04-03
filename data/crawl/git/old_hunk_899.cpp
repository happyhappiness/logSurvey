		die("transport '%s' not allowed", type);
}

int transport_restrict_protocols(void)
{
	return !!protocol_whitelist();
}

struct transport *transport_get(struct remote *remote, const char *url)
{
	const char *helper;
