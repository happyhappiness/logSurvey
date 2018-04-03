	o->df_conflict_entry = dfc;

	if (len) {
		const char *prefix = o->prefix ? o->prefix : "";
		struct traverse_info info;

		setup_traverse_info(&info, prefix);
		info.fn = unpack_callback;
		info.data = o;

		if (traverse_trees(len, t, &info) < 0)
			return unpack_failed(o, NULL);
	}

	/* Any left-over entries in the index? */
	if (o->merge) {
		while (o->pos < active_nr) {
			struct cache_entry *ce = active_cache[o->pos];
			if (unpack_index_entry(ce, o) < 0)
				return unpack_failed(o, NULL);
		}
	}

	if (o->trivial_merges_only && o->nontrivial_merge)
		return unpack_failed(o, "Merge requires file-level merging");

	check_updates(o);
	return 0;
}