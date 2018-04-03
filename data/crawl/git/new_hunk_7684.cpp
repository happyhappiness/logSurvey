			  sha1_to_hex(object),
			  typename(type),
			  tag,
			  git_committer_info(IDENT_ERROR_ON_NO_NAME));

	if (header_len > sizeof(header_buf) - 1)
		die("tag header too big.");
