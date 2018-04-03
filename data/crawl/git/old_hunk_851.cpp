
	if (has_unstaged_changes(1))
		return error(_("cannot rebase: You have unstaged changes."));
	if (!has_uncommitted_changes(0))
		return 0;

	if (file_exists(rebase_path_amend())) {
		struct strbuf rev = STRBUF_INIT;