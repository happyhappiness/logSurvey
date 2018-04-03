	if (ref_list->verbose || ref_list->with_commit || merge_filter != NO_FILTER) {
		commit = lookup_commit_reference_gently(sha1, 1);
		if (!commit) {
			cb->ret = error("branch '%s' does not point at a commit", refname);
			return 0;
		}

