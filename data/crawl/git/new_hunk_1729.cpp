	if (!cmd)
		cmd = "git-help";

	restore_sigpipe_to_default();

	git_setup_gettext();
