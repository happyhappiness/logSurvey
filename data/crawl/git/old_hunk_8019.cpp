	return NULL;
}

#endif

static const struct transport_ops curl_transport = {
	/* set_option */	NULL,
	/* get_refs_list */	get_refs_via_curl,
	/* fetch */		fetch_objs_via_walker,
	/* push */		curl_transport_push,
	/* disconnect */	disconnect_walker
};
