	/* Remotes are only allowed to fetch actual refs */
	if (remote) {
		char *ref = NULL;
		const char *refname, *colon = NULL;

		colon = strchr(name, ':');
		if (colon)
			refname = xstrndup(name, colon - name);
		else
			refname = name;

		if (!dwim_ref(refname, strlen(refname), sha1, &ref))
			die("no such ref: %s", refname);
		if (refname != name)
			free((void *)refname);
		free(ref);
	}

	if (get_sha1(name, sha1))
		die("Not a valid object name");

	commit = lookup_commit_reference_gently(sha1, 1);
	if (commit) {