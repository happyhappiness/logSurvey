
	for (i = 0; i < q->nr; i++) {
		struct diff_filespec *one = q->queue[i]->one;
		int is_missing = !(one->mode && !is_null_sha1(one->sha1));
		struct cache_entry *ce;

		if (is_missing && !intent_to_add) {
			remove_file_from_cache(one->path);
			continue;
		}

		ce = make_cache_entry(one->mode, one->sha1, one->path,
				      0, 0);
		if (!ce)
			die(_("make_cache_entry failed for path '%s'"),