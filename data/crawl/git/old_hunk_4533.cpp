		 */
		if (local_changes && staged_changes) {
			if (!index_only || !(ce->ce_flags & CE_INTENT_TO_ADD))
				errs = error("'%s' has staged content different "
					     "from both the file and the HEAD\n"
					     "(use -f to force removal)", name);
		}
		else if (!index_only) {
			if (staged_changes)
				errs = error("'%s' has changes staged in the index\n"
					     "(use --cached to keep the file, "
					     "or -f to force removal)", name);
			if (local_changes)
				errs = error("'%s' has local modifications\n"
					     "(use --cached to keep the file, "
					     "or -f to force removal)", name);
		}
	}
	return errs;
