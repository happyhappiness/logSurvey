		return fast_forward_to(commit->object.sha1, head);

	if (parent && parse_commit(parent) < 0)
		die("%s: cannot parse parent commit %s",
		    me, sha1_to_hex(parent->object.sha1));

	if (get_message(commit->buffer, &msg) != 0)