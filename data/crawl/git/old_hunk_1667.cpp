				fprintf(stderr, "BUG: %d %.*s\n", ce_stage(ce),
					(int)ce_namelen(ce), ce->name);
		}
		die("Bug in merge-recursive.c");
	}

	if (!active_cache_tree)
