	return rc;
}

struct tree *write_tree_from_memory(void)
{
	struct tree *result = NULL;

	if (unmerged_cache()) {
		int i;
		output(0, "There are unmerged index entries:");
		for (i = 0; i < active_nr; i++) {
			struct cache_entry *ce = active_cache[i];
			if (ce_stage(ce))
				output(0, "%d %.*s", ce_stage(ce), ce_namelen(ce), ce->name);
		}
		return NULL;
	}
