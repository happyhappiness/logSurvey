
	track = git_branch_track;

	head = resolve_refdup("HEAD", head_sha1, 0, NULL);
	if (!head)
		die(_("Failed to resolve HEAD as a valid ref."));
	if (!strcmp(head, "HEAD")) {
		detached = 1;
	} else {
