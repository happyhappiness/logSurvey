	for (i = 0; i < the_index.cache_nr; i++) {
		struct cache_entry *ce = the_index.cache[i];
		printf("%06o %s %d\t%s\n", ce->ce_mode,
		       oid_to_hex(&ce->oid), ce_stage(ce), ce->name);
	}
	printf("replacements:");
	if (si->replace_bitmap)