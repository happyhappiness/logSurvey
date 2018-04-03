{
	const struct ref *r;

	for (r = local_refs; r; r = r->next) {
		if (!r->peer_ref)
			continue;
		add_packed_ref(r->peer_ref->name, r->old_sha1);
	}

	pack_refs(PACK_REFS_ALL);
}

static void write_followtags(const struct ref *refs, const char *msg)
