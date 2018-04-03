
	/* if not appending, truncate FETCH_HEAD */
	if (!append && !dry_run) {
		int errcode = truncate_fetch_head();
		if (errcode)
			return errcode;
	}

	ref_map = get_ref_map(transport, refs, ref_count, tags, &autotags);
