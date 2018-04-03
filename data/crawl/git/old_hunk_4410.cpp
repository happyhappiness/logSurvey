		    me, sha1_to_hex(parent->object.sha1));

	if (get_message(commit->buffer, &msg) != 0)
		die("Cannot get commit message for %s",
				sha1_to_hex(commit->object.sha1));

	/*
