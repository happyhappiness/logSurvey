		for (i = 0; i < active_nr; i++) {
			struct cache_entry *ce = active_cache[i];
			if (ce_stage(ce))
				output(o, 0, "%d %.*s", ce_stage(ce), ce_namelen(ce), ce->name);
		}
		return NULL;
	}
