		show_diffstat = 0;

	if (squash) {
		if (fast_forward == FF_NO)
			die(_("You cannot combine --squash with --no-ff."));
		option_commit = 0;
	}

	if (!abort_current_merge) {
		if (!argc) {
			if (default_to_upstream)
