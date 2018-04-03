	int i = 0, pos = 0;
	unsigned char head_sha1[20];
	const char *current_branch;

	/* get current branch */
	current_branch = resolve_ref("HEAD", head_sha1, 1, NULL);
	if (!current_branch)
		die("No current branch");
	if (!prefixcmp(current_branch, "refs/heads/"))
		current_branch += 11;
	current_branch = xstrdup(current_branch);

	/* get a line */
	while (pos < in->len) {
