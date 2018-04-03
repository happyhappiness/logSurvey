		goto leave;
	} else if (allow)
		flags |= ALLOW_EMPTY;
	if (!opts->no_commit)
fast_forward_edit:
		res = run_git_commit(msg_file, opts, flags);

	if (!res && final_fixup) {
		unlink(rebase_path_fixup_msg());
