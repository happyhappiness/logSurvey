	} else
		return 0;

	/* Filter with with_commit if specified */
	if (!has_commit(sha1, ref_list->with_commit))
		return 0;

	/* Don't add types the caller doesn't want */
