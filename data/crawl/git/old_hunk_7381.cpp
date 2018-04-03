	rev.boundary = 1;
	while ((commit = get_revision(&rev)) != NULL) {
		if (commit->object.flags & BOUNDARY) {
			fprintf(stderr, "Boundary %s\n", sha1_to_hex(commit->object.sha1));
			boundary_count++;
			origin = (boundary_count == 1) ? commit : NULL;
			continue;