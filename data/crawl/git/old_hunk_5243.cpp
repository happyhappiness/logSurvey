	ref = transport_get_remote_refs(transport);
	if (transport_disconnect(transport))
		return 1;
	for ( ; ref; ref = ref->next) {
		if (!check_ref_type(ref, flags))
			continue;
