	for (rm = ref_map; rm; rm = rm->next) {
		if (rm->peer_ref)
			read_ref(rm->peer_ref->name, rm->peer_ref->old_sha1);
	}

	if (fetch_refs(transport, ref_map)) {