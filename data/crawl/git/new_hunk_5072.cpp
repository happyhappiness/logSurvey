	if (errno == ENOENT)
		return 0;
	return o->gently ? -1 :
		add_rejected_path(o, error_type, ce->name);
}

static int verify_uptodate(struct cache_entry *ce,