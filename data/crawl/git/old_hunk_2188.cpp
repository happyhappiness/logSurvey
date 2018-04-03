	if (get_sha1("HEAD", orig_head))
		hashclr(orig_head);

	if (opt_rebase) {
		int autostash = config_autostash;

		if (is_null_sha1(orig_head) && !is_cache_unborn())
			die(_("Updating an unborn branch with changes added to the index."));
