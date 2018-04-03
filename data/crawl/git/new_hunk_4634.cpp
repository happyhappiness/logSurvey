	}

	if (!transport->get_refs_list || !transport->fetch)
		die(_("Don't know how to fetch from %s"), transport->url);

	/* if not appending, truncate FETCH_HEAD */
	if (!append && !dry_run) {
