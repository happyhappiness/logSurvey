	prepare_alt_odb();

	memset(&ds, 0, sizeof(ds));
	if (flags & GET_SHA1_COMMIT)
		ds.fn = disambiguate_commit_only;
	else if (flags & GET_SHA1_COMMITTISH)