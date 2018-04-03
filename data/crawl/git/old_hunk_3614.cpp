		 */
		if (local_changes && staged_changes) {
			if (!index_only || !(ce->ce_flags & CE_INTENT_TO_ADD))
				errs = error(_("'%s' has staged content different "
					     "from both the file and the HEAD\n"
					     "(use -f to force removal)"), name);
		}
		else if (!index_only) {
			if (staged_changes)
				errs = error(_("'%s' has changes staged in the index\n"
					     "(use --cached to keep the file, "
					     "or -f to force removal)"), name);
			if (local_changes) {
				if (S_ISGITLINK(ce->ce_mode) &&
				    !submodule_uses_gitfile(name)) {
					errs = error(_("submodule '%s' (or one of its nested "
						     "submodules) uses a .git directory\n"
						     "(use 'rm -rf' if you really want to remove "
						     "it including all of its history)"), name);
				} else
					errs = error(_("'%s' has local modifications\n"
						     "(use --cached to keep the file, "
						     "or -f to force removal)"), name);
			}
		}
	}
	return errs;
}

