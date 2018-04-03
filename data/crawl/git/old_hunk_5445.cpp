
	if (unmerged_cache()) {
		int i;
		output(o, 0, "There are unmerged index entries:");
		for (i = 0; i < active_nr; i++) {
			struct cache_entry *ce = active_cache[i];
			if (ce_stage(ce))
				output(o, 0, "%d %.*s", ce_stage(ce),
				       (int)ce_namelen(ce), ce->name);
		}
		return NULL;
	}

	if (!active_cache_tree)