	for (r = local_refs; r; r = r->next) {
		if (!r->peer_ref)
			continue;
		if (ref_transaction_create(t, r->peer_ref->name, r->old_sha1,
					   0, NULL, &err))
			die("%s", err.buf);
	}
