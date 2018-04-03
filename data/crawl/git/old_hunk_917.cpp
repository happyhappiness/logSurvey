		goto done;
	}

	if (read_cache_unmerged())
		die_resolve_conflict("merge");

