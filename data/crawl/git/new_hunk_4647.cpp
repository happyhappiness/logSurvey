	if (amend && initial_commit)
		die(_("You have nothing to amend."));
	if (amend && in_merge)
		die(_("You are in the middle of a merge -- cannot amend."));
	if (fixup_message && squash_message)
		die(_("Options --squash and --fixup cannot be used together"));
	if (use_message)
		f++;
	if (edit_message)
