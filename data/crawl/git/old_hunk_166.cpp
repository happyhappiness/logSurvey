	if (verbose)
		fprintf(stderr, "Checking HEAD link\n");

	head_points_at = resolve_ref_unsafe("HEAD", 0, head_oid.hash, NULL);
	if (!head_points_at) {
		errors_found |= ERROR_REFS;
		return error("Invalid HEAD");
