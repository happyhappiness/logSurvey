	struct packed_ref_cache *packed_ref_cache = get_packed_ref_cache(refs);

	if (!packed_ref_cache->lock)
		die("BUG: packed refs not locked");
	add_ref_entry(get_packed_ref_dir(packed_ref_cache),
		      create_ref_entry(refname, oid, REF_ISPACKED, 1));
}
