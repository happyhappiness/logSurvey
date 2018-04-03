	return hunk_no;
}

static int find_conflict(struct string_list *conflict)
{
	int i;
	if (read_cache() < 0)
		return error("Could not read index");
	for (i = 0; i+1 < active_nr; i++) {
		struct cache_entry *e2 = active_cache[i];
		struct cache_entry *e3 = active_cache[i+1];
		if (ce_stage(e2) == 2 &&
		    ce_stage(e3) == 3 &&
		    ce_same_name(e2, e3) &&
		    S_ISREG(e2->ce_mode) &&
		    S_ISREG(e3->ce_mode)) {
			string_list_insert(conflict, (const char *)e2->name);
			i++; /* skip over both #2 and #3 */
		}
	}
	return 0;
