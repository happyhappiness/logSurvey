	if (verbose)
		fprintf(stderr, "Checking HEAD link\n");

	head_points_at = resolve_ref_unsafe("HEAD", 0, head_oid.hash, &flag);
	if (!head_points_at)
		return error("Invalid HEAD");
	if (!strcmp(head_points_at, "HEAD"))
