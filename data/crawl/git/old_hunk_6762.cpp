		alias->ce_flags |= CE_ADDED;
		return 0;
	}
	if (index_path(ce->sha1, path, st, 1))
		return error("unable to index file %s", path);
	if (ignore_case && alias && different_name(ce, alias))
		ce = create_alias_ce(ce, alias);
	ce->ce_flags |= CE_ADDED;
