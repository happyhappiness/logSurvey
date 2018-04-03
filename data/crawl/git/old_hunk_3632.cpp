	if (!refs_found)
		return -1;

	if (warn_ambiguous_refs && refs_found > 1)
		warning(warn_msg, len, str);

	if (reflog_len) {
