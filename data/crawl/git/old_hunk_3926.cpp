
	commit_info_init(ret);

	/*
	 * We've operated without save_commit_buffer, so
	 * we now need to populate them for output.
	 */
	if (!commit->buffer) {
		enum object_type type;
		unsigned long size;
		commit->buffer =
			read_sha1_file(commit->object.sha1, &type, &size);
		if (!commit->buffer)
			die("Cannot read commit %s",
			    sha1_to_hex(commit->object.sha1));
	}
	encoding = get_log_output_encoding();
	message = logmsg_reencode(commit, encoding);
	get_ac_line(message, "\nauthor ",
