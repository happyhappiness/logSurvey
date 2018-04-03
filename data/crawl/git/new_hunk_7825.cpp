
static int unmerged_files(void)
{
	int i;
	read_cache();
	for (i = 0; i < active_nr; i++) {
		struct cache_entry *ce = active_cache[i];
		if (ce_stage(ce))
			return 1;
	}
	return 0;
}

static int reset_index_file(const unsigned char *sha1, int is_hard_reset)
