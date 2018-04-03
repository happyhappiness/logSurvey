
	commit_info_init(ret);

	encoding = get_log_output_encoding();
	message = logmsg_reencode(commit, encoding);
	get_ac_line(message, "\nauthor ",
