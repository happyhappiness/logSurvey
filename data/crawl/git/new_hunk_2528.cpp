		/* TRANSLATORS: The first %s will be "revert" or
		   "cherry-pick", the second %s a SHA1 */
		return error(_("%s: cannot parse parent commit %s"),
			action_name(opts), oid_to_hex(&parent->object.oid));

	if (get_message(commit, &msg) != 0)
		return error(_("Cannot get commit message for %s"),
			oid_to_hex(&commit->object.oid));

	/*
	 * "commit" is an existing commit.  We would want to apply
