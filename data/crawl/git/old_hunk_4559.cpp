	memset(branch_head, 0, sizeof(branch_head));
	remote_head = peel_to_type(remote, 0, NULL, OBJ_COMMIT);
	if (!remote_head)
		die("'%s' does not point to a commit", remote);

	if (dwim_ref(remote, strlen(remote), branch_head, &found_ref) > 0) {
		if (!prefixcmp(found_ref, "refs/heads/")) {
