		die("Don't know how to fetch from %s", transport->url);

	/* if not appending, truncate FETCH_HEAD */
	if (!append)
		fclose(fopen(git_path("FETCH_HEAD"), "w"));

	ref_map = get_ref_map(transport, refs, ref_count, tags, &autotags);
