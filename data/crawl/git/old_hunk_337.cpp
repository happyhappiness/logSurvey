		if (pathspec && !ce_path_match(ce, pathspec, NULL))
			continue;

		if (chmod_cache_entry(ce, force_mode) < 0)
			fprintf(stderr, "cannot chmod '%s'", ce->name);
	}
}
