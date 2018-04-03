	packed_refs->cache->root->flag &= ~REF_INCOMPLETE;

	f = fopen(packed_refs_file, "r");
	if (!f)
		return packed_refs;

	stat_validity_update(&packed_refs->validity, fileno(f));
