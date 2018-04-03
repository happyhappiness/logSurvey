		return -1;
	if (get_sha1("HEAD", sha1) && (opts->action == REPLAY_REVERT))
		return error(_("Can't revert as initial commit"));
	if (save_head(sha1_to_hex(sha1)))
		return -1;
	save_opts(opts);
	return pick_commits(todo_list, opts);
}