		/* TRANSLATORS: The first %s will be "revert" or
		   "cherry-pick", the second %s a SHA1 */
		return error(_("%s: cannot parse parent commit %s"),
			action_name(opts), sha1_to_hex(parent->object.sha1));

	if (get_message(commit, &msg) != 0)
		return error(_("Cannot get commit message for %s"),
			sha1_to_hex(commit->object.sha1));

	/*
	 * "commit" is an existing commit.  We would want to apply
