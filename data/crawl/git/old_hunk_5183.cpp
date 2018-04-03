		commit = lookup_commit_reference_gently(sha1, 1);
		if (!commit) {
			cb->ret = error("branch '%s' does not point at a commit", refname);
			return cb->ret;
		}

		/* Filter with with_commit if specified */
