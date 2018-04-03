	prepare_alt_odb();

	memset(&ds, 0, sizeof(ds));

	if (HAS_MULTI_BITS(flags & GET_SHA1_DISAMBIGUATORS))
		die("BUG: multiple get_short_sha1 disambiguator flags");

	if (flags & GET_SHA1_COMMIT)
		ds.fn = disambiguate_commit_only;
	else if (flags & GET_SHA1_COMMITTISH)