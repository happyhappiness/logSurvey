int read_index_unmerged(struct index_state *istate)
{
	int i;
	struct cache_entry **dst;
	struct cache_entry *last = NULL;

	read_index(istate);
	dst = istate->cache;
	for (i = 0; i < istate->cache_nr; i++) {
		struct cache_entry *ce = istate->cache[i];
		if (ce_stage(ce)) {
			remove_name_hash(ce);
			if (last && !strcmp(ce->name, last->name))
				continue;
			cache_tree_invalidate_path(istate->cache_tree, ce->name);
			last = ce;
			continue;
		}
		*dst++ = ce;
	}
	istate->cache_nr = dst - istate->cache;
	return !!last;
}
