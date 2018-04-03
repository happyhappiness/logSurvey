		unsigned long size;
		commit->buffer =
			read_sha1_file(commit->object.sha1, &type, &size);
	}
	ret->author = author_buf;
	get_ac_line(commit->buffer, "\nauthor ",
