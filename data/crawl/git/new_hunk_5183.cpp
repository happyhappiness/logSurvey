		commit = lookup_commit_reference_gently(sha1, 1);
		if (!commit) {
			cb->ret = error("branch '%s' does not point at a commit", refname);
			return 0;
		}

		/* Filter with with_commit if specified */
