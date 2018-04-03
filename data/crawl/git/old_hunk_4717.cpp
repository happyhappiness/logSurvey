
	head = resolve_ref("HEAD", head_sha1, 0, NULL);
	if (!head)
		die("Failed to resolve HEAD as a valid ref.");
	head = xstrdup(head);
	if (!strcmp(head, "HEAD")) {
		detached = 1;
	} else {
		if (prefixcmp(head, "refs/heads/"))
			die("HEAD not found below refs/heads!");
		head += 11;
	}
	hashcpy(merge_filter_ref, head_sha1);
