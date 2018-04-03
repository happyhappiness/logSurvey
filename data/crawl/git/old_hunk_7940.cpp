	return fetch_objs_via_walker(transport, nr_objs, to_fetch);
}

#else

static struct ref *get_refs_via_curl(const struct transport *transport)
{
	die("Cannot fetch from '%s' without curl ...", transport->url);
	return NULL;
}

static int fetch_objs_via_curl(struct transport *transport,
				 int nr_objs, struct ref **to_fetch)
{
	die("Cannot fetch from '%s' without curl ...", transport->url);
	return -1;
}

#endif

struct bundle_transport_data {
