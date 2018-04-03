	int recovery = 0;

	if (!oldname)
		die(_("cannot rename the current branch while not on any."));

	if (strbuf_check_branch_ref(&oldref, oldname)) {
		/*
