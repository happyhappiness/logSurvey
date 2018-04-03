	funny = 0;
	for (i = 0; i < entries; i++) {
		struct cache_entry *ce = cache[i];
		if (ce_stage(ce)) {
			if (10 < ++funny) {
				fprintf(stderr, "...\n");
				break;
			}
			fprintf(stderr, "%s: unmerged (%s)\n",
				ce->name, sha1_to_hex(ce->sha1));
		}
	}
	if (funny)
