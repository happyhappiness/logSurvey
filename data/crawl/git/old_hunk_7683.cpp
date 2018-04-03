	int len;

	if (!*signingkey) {
		if (strlcpy(signingkey, git_committer_info(1),
				sizeof(signingkey)) > sizeof(signingkey) - 1)
			return error("committer info too long.");
		bracket = strchr(signingkey, '>');
