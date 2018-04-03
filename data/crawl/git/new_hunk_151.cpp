		goto leave;
	} else if (allow)
		flags |= ALLOW_EMPTY;
	if (!opts->no_commit) {
fast_forward_edit:
		if (author || command == TODO_REVERT || (flags & AMEND_MSG))
			res = do_commit(msg_file, author, opts, flags);
		else
			res = error(_("unable to parse commit author"));
	}

	if (!res && final_fixup) {
		unlink(rebase_path_fixup_msg());
