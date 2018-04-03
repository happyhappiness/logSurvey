	else
		parent = commit->parents->item;

	if (parent && parse_commit(parent) < 0)
		die("%s: cannot parse parent commit %s",
		    me, sha1_to_hex(parent->object.sha1));

	if (get_message(commit->buffer, &msg) != 0)
		die("Cannot get commit message for %s",
				sha1_to_hex(commit->object.sha1));

	/*
	 * "commit" is an existing commit.  We would want to apply
	 * the difference it introduces since its first parent "prev"
