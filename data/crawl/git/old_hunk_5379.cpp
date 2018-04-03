	else
		parent = commit->parents->item;

	if (!(message = commit->buffer))
		die ("Cannot get commit message for %s",
				sha1_to_hex(commit->object.sha1));
