	/* Remotes are only allowed to fetch actual refs */
	if (remote) {
		char *ref = NULL;
		if (!dwim_ref(name, strlen(name), sha1, &ref))
			die("no such ref: %s", name);
		free(ref);
	}
	else {
		if (get_sha1(name, sha1))
			die("Not a valid object name");
	}

	commit = lookup_commit_reference_gently(sha1, 1);
	if (commit) {