	} else
		return 0;

	commit = lookup_commit_reference_gently(sha1, 1);
	if (!commit)
		return error("branch '%s' does not point at a commit", refname);

	/* Filter with with_commit if specified */
	if (!has_commit(commit, ref_list->with_commit))
		return 0;

	/* Don't add types the caller doesn't want */
