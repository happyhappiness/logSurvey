	strcpy(newh, find_unique_abbrev(sha1_new, DEFAULT_ABBREV));

	if (in_merge_bases(current, &updated, 1)) {
		fprintf(stderr, "* %s: fast forward to %s\n",
			name, note);
		fprintf(stderr, "  old..new: %s..%s\n", oldh, newh);
		return update_ref_env("fast forward", name, sha1_new, sha1_old);
	}
	if (!force) {
		fprintf(stderr,
			"* %s: not updating to non-fast forward %s\n",
			name, note);
		fprintf(stderr,
			"  old...new: %s...%s\n", oldh, newh);
		return 1;
	}
	fprintf(stderr,
		"* %s: forcing update to non-fast forward %s\n",
		name, note);
	fprintf(stderr, "  old...new: %s...%s\n", oldh, newh);
	return update_ref_env("forced-update", name, sha1_new, sha1_old);
