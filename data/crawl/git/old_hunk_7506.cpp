	}

	if (o->trivial_merges_only && o->nontrivial_merge)
		die("Merge requires file-level merging");

	check_updates(active_cache, active_nr, o);
	return 0;
}

/* Here come the merge functions */

static void reject_merge(struct cache_entry *ce)
{
	die("Entry '%s' would be overwritten by merge. Cannot merge.",
	    ce->name);
}

static int same(struct cache_entry *a, struct cache_entry *b)
