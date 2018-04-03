	}
	if (errno == ENOENT)
		return 0;
	return o->gently ? -1 :
		error("Entry '%s' not uptodate. Cannot merge.", ce->name);
}

static void invalidate_ce_path(struct cache_entry *ce)
