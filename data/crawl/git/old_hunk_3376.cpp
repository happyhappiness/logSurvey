		if (index_path(ce->sha1, path, st, HASH_WRITE_OBJECT))
			return error("unable to index file %s", path);
	} else
		record_intent_to_add(ce);

	if (ignore_case && alias && different_name(ce, alias))
		ce = create_alias_ce(ce, alias);