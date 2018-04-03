{
	struct transport *ret = xcalloc(1, sizeof(*ret));

	ret->remote = remote;
	ret->url = url;

