			create_seq_dir() < 0)
		return -1;
	if (get_sha1("HEAD", sha1) && (opts->action == REPLAY_REVERT))
		return error(_("can't revert as initial commit"));
	if (save_head(sha1_to_hex(sha1)))
		return -1;
	if (save_opts(opts))
