		die("You have nothing to amend.");
	if (amend && in_merge)
		die("You are in the middle of a merge -- cannot amend.");

	if (use_message)
		f++;
	if (edit_message)