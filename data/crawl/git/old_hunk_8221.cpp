	free_ref_list(&ref_list);
}

static char *config_repo;
static char *config_remote;
static const char *start_ref;

static int get_remote_branch_name(const char *value)
{
	const char *colon;
	const char *end;

	if (*value == '+')
		value++;

	colon = strchr(value, ':');
	if (!colon)
		return 0;

	end = value + strlen(value);

	/*
	 * Try an exact match first.  I.e. handle the case where the
	 * value is "$anything:refs/foo/bar/baz" and start_ref is exactly
	 * "refs/foo/bar/baz". Then the name at the remote is $anything.
	 */
	if (!strcmp(colon + 1, start_ref)) {
		/* Truncate the value before the colon. */
		nfasprintf(&config_repo, "%.*s", colon - value, value);
		return 1;
	}

	/*
	 * Is this a wildcard match?
	 */
	if ((end - 2 <= value) || end[-2] != '/' || end[-1] != '*' ||
	    (colon - 2 <= value) || colon[-2] != '/' || colon[-1] != '*')
		return 0;

	/*
	 * Value is "refs/foo/bar/<asterisk>:refs/baz/boa/<asterisk>"
	 * and start_ref begins with "refs/baz/boa/"; the name at the
	 * remote is refs/foo/bar/ with the remaining part of the
	 * start_ref.  The length of the prefix on the RHS is (end -
	 * colon - 2), including the slash immediately before the
	 * asterisk.
	 */
	if ((strlen(start_ref) < end - colon - 2) ||
	    memcmp(start_ref, colon + 1, end - colon - 2))
		return 0; /* does not match prefix */

	/* Replace the asterisk with the remote branch name.  */
	nfasprintf(&config_repo, "%.*s%s",
		   (colon - 1) - value, value,
		   start_ref + (end - colon - 2));
	return 1;
}

static int get_remote_config(const char *key, const char *value)
{
	const char *var;
	if (prefixcmp(key, "remote."))
		return 0;

	var = strrchr(key, '.');
	if (var == key + 6 || strcmp(var, ".fetch"))
		return 0;
	/*
	 * Ok, we are looking at key == "remote.$foo.fetch";
	 */
	if (get_remote_branch_name(value))
		nfasprintf(&config_remote, "%.*s", var - (key + 7), key + 7);

	return 0;
}

static void set_branch_merge(const char *name, const char *config_remote,
			     const char *config_repo)
{
	char key[1024];
	if (sizeof(key) <=
	    snprintf(key, sizeof(key), "branch.%s.remote", name))
		die("what a long branch name you have!");
	git_config_set(key, config_remote);

	/*
	 * We do not have to check if we have enough space for
	 * the 'merge' key, since it's shorter than the
	 * previous 'remote' key, which we already checked.
	 */
	snprintf(key, sizeof(key), "branch.%s.merge", name);
	git_config_set(key, config_repo);
}

static void set_branch_defaults(const char *name, const char *real_ref)
{
	/*
	 * name is the name of new branch under refs/heads;
	 * real_ref is typically refs/remotes/$foo/$bar, where
	 * $foo is the remote name (there typically are no slashes)
	 * and $bar is the branch name we map from the remote
	 * (it could have slashes).
	 */
	start_ref = real_ref;
	git_config(get_remote_config);
	if (!config_repo && !config_remote &&
	    !prefixcmp(real_ref, "refs/heads/")) {
		set_branch_merge(name, ".", real_ref);
		printf("Branch %s set up to track local branch %s.\n",
		       name, real_ref);
	}

	if (config_repo && config_remote) {
		set_branch_merge(name, config_remote, config_repo);
		printf("Branch %s set up to track remote branch %s.\n",
		       name, real_ref);
	}

	if (config_repo)
		free(config_repo);
	if (config_remote)
		free(config_remote);
}

static void create_branch(const char *name, const char *start_name,
