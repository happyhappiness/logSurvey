		/* Nothing changed, really */
		free(ce);
		ce_mark_uptodate(alias);
		return 0;
	}

	if (index_path(ce->sha1, path, &st, 1))
		die("unable to index file %s", path);
	if (add_index_entry(istate, ce, ADD_CACHE_OK_TO_ADD|ADD_CACHE_OK_TO_REPLACE))
		die("unable to add %s to index",path);
	if (verbose)