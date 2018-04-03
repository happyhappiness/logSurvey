			  tag,
			  git_committer_info(1));

	if (header_len > sizeof(header_buf) - 1)
		die("tag header too big.");

	if (!message) {
