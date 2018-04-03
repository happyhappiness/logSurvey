	return pos;
}

static int check_stage(int stage, struct cache_entry *ce, int pos)
{
	while (pos < active_nr &&
	       !strcmp(active_cache[pos]->name, ce->name)) {
		if (ce_stage(active_cache[pos]) == stage)
			return 0;
		pos++;
	}
	return error("path '%s' does not have %s version",
		     ce->name,
		     (stage == 2) ? "our" : "their");
}

static int checkout_stage(int stage, struct cache_entry *ce, int pos,
			  struct checkout *state)
{
	while (pos < active_nr &&
	       !strcmp(active_cache[pos]->name, ce->name)) {
		if (ce_stage(active_cache[pos]) == stage)
			return checkout_entry(active_cache[pos], state, NULL);
		pos++;
	}
	return error("path '%s' does not have %s version",
		     ce->name,
		     (stage == 2) ? "our" : "their");
}

static int checkout_paths(struct tree *source_tree, const char **pathspec,
			  struct checkout_opts *opts)
