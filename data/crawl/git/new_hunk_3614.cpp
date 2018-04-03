		 */
		if (local_changes && staged_changes) {
			if (!index_only || !(ce->ce_flags & CE_INTENT_TO_ADD))
				string_list_append(&files_staged, name);
		}
		else if (!index_only) {
			if (staged_changes)
				string_list_append(&files_cached, name);
			if (local_changes) {
				if (S_ISGITLINK(ce->ce_mode) &&
				    !submodule_uses_gitfile(name))
					string_list_append(&files_submodule, name);
				else
					string_list_append(&files_local, name);
			}
		}
	}
	print_error_files(&files_staged,
			  Q_("the following file has staged content different "
			     "from both the\nfile and the HEAD:",
			     "the following files have staged content different"
			     " from both the\nfile and the HEAD:",
			     files_staged.nr),
			  _("\n(use -f to force removal)"),
			  &errs);
	string_list_clear(&files_staged, 0);
	print_error_files(&files_cached,
			  Q_("the following file has changes "
			     "staged in the index:",
			     "the following files have changes "
			     "staged in the index:", files_cached.nr),
			  _("\n(use --cached to keep the file,"
			    " or -f to force removal)"),
			  &errs);
	string_list_clear(&files_cached, 0);
	print_error_files(&files_submodule,
			  Q_("the following submodule (or one of its nested "
			     "submodule)\nuses a .git directory:",
			     "the following submodules (or one of its nested "
			     "submodule)\nuse a .git directory:",
			     files_submodule.nr),
			  _("\n(use 'rm -rf' if you really "
			    "want to remove it including all "
			    "of its history)"),
			  &errs);
	string_list_clear(&files_submodule, 0);
	print_error_files(&files_local,
			  Q_("the following file has local modifications:",
			     "the following files have local modifications:",
			     files_local.nr),
			  _("\n(use --cached to keep the file,"
			    " or -f to force removal)"),
			  &errs);
	string_list_clear(&files_local, 0);

	return errs;
}

