		die(_("Cannot rebase onto multiple branches."));

	if (opt_rebase) {
		if (!autostash) {
			struct commit_list *list = NULL;
			struct commit *merge_head, *head;
