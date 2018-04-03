			sha1_to_hex(local->object.sha1),
			sha1_to_hex(base_sha1));

	if (!hashcmp(remote->object.sha1, base_sha1)) {
		/* Already merged; result == local commit */
		if (o->verbosity >= 2)
			printf("Already up-to-date!\n");
		hashcpy(result_sha1, local->object.sha1);
		goto found_result;
	}
	if (!hashcmp(local->object.sha1, base_sha1)) {
		/* Fast-forward; result == remote commit */
		if (o->verbosity >= 2)
			printf("Fast-forward\n");
		hashcpy(result_sha1, remote->object.sha1);
		goto found_result;
	}

	result = merge_from_diffs(o, base_tree_sha1, local->tree->object.sha1,
				  remote->tree->object.sha1, local_tree);

	if (result != 0) { /* non-trivial merge (with or without conflicts) */
		/* Commit (partial) result */
