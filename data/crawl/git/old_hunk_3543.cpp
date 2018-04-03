		 * only one common.
		 */
		refresh_cache(REFRESH_QUIET);
		if (allow_trivial && !fast_forward_only) {
			/* See if it is really trivial. */
			git_committer_info(IDENT_STRICT);
			printf(_("Trying really trivial in-index merge...\n"));
