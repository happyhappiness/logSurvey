		branch.item = lookup_commit_reference_gently(sha1, 1);
		if (!branch.item)
			die("Unable to lookup tip of branch %s", refname);
		if (merge_filter == SHOW_NOT_MERGED &&
		    has_commit(merge_filter_ref, &branch))
			return 0;
		if (merge_filter == SHOW_MERGED &&
		    !has_commit(merge_filter_ref, &branch))
			return 0;
	}

	/* Resize buffer */
