
	/* iterate over new parents */
	for (i = 1; i < mergetag_data->argc; i++) {
		struct object_id oid;
		if (get_sha1(mergetag_data->argv[i], oid.hash) < 0)
			die(_("Not a valid object name: '%s'"), mergetag_data->argv[i]);
		if (!oidcmp(&tag->tagged->oid, &oid))
			return; /* found */
	}

