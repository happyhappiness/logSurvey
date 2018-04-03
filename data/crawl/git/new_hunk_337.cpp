		if (pathspec && !ce_path_match(ce, pathspec, NULL))
			continue;

		if (chmod_cache_entry(ce, flip) < 0)
			fprintf(stderr, "cannot chmod %cx '%s'\n", flip, ce->name);
	}
}
