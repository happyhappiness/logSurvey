
	if (!*signingkey) {
		if (strlcpy(signingkey, git_committer_info(1),
				sizeof(signingkey)) >= sizeof(signingkey))
			return error("committer info too long.");
		bracket = strchr(signingkey, '>');
		if (bracket)
