		unsigned long size;
		commit->buffer =
			read_sha1_file(commit->object.sha1, &type, &size);
		if (!commit->buffer)
			die("Cannot read commit %s",
			    sha1_to_hex(commit->object.sha1));
	}
	ret->author = author_buf;
	get_ac_line(commit->buffer, "\nauthor ",
