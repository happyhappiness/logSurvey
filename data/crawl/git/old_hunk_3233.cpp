	 */
	strbuf_addstr(&dirname, refname + dirname.len);
	strbuf_addch(&dirname, '/');
	pos = search_ref_dir(dir, dirname.buf, dirname.len);

	if (pos >= 0) {
		/*
		 * We found a directory named "$refname/" (e.g.,
		 * "refs/foo/bar/"). It is a problem iff it contains
		 * any ref that is not in "skip".
		 */
		struct nonmatching_ref_data data;
		struct ref_entry *entry = dir->entries[pos];

		dir = get_ref_dir(entry);
		data.skip = skip;
		sort_ref_dir(dir);
		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data)) {
			ret = 1;
			goto cleanup;
		}

		error("'%s' exists; cannot create '%s'",
		      data.conflicting_refname, refname);
		goto cleanup;
	}

	ret = 1;

cleanup:
