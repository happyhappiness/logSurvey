	return NULL;
}

static int fetch_objs_via_curl(struct transport *transport,
				 int nr_objs, struct ref **to_fetch)
{
	die("Cannot fetch from '%s' without curl ...", transport->url);
	return -1;
}

#endif

static const struct transport_ops curl_transport = {
	/* set_option */	NULL,
	/* get_refs_list */	get_refs_via_curl,
	/* fetch */		fetch_objs_via_curl,
	/* push */		curl_transport_push,
	/* disconnect */	disconnect_walker
};
