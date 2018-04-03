		     (stage == 2) ? "our" : "their");
}

static int check_all_stages(struct cache_entry *ce, int pos)
{
	if (ce_stage(ce) != 1 ||
	    active_nr <= pos + 2 ||
	    strcmp(active_cache[pos+1]->name, ce->name) ||
	    ce_stage(active_cache[pos+1]) != 2 ||
	    strcmp(active_cache[pos+2]->name, ce->name) ||
	    ce_stage(active_cache[pos+2]) != 3)
		return error("path '%s' does not have all three versions",
			     ce->name);
	return 0;
}

static int checkout_stage(int stage, struct cache_entry *ce, int pos,
			  struct checkout *state)
{
