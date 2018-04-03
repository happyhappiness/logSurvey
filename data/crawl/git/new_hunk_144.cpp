		goto out;
	}

	if (find_hook("prepare-commit-msg")) {
		res = run_prepare_commit_msg_hook(msg, hook_commit);
		if (res)
			goto out;
		if (strbuf_read_file(&commit_msg, git_path_commit_editmsg(),
				     2048) < 0) {
			res = error_errno(_("unable to read commit message "
					      "from '%s'"),
					    git_path_commit_editmsg());
			goto out;
		}
		msg = &commit_msg;
	}

	cleanup = (flags & CLEANUP_MSG) ? COMMIT_MSG_CLEANUP_ALL :
					  opts->default_msg_cleanup;

	if (cleanup != COMMIT_MSG_CLEANUP_NONE)
		strbuf_stripspace(msg, cleanup == COMMIT_MSG_CLEANUP_ALL);
	if (!opts->allow_empty_message && message_is_empty(msg, cleanup)) {
		res = 1; /* run 'git commit' to display error message */
		goto out;
	}

	if (commit_tree_extended(msg->buf, msg->len, tree.hash, parents,
				 oid->hash, author, opts->gpg_sign, extra)) {
		res = error(_("failed to write commit object"));
