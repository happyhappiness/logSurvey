		 * If this is the head, and it's not okay to update
		 * the head, and the old value of the head isn't empty...
		 */
		fprintf(stderr,
			" * %s: Cannot fetch into the current branch.\n",
			ref->name);
		return 1;
	}

	if (!is_null_sha1(ref->old_sha1) &&
	    !prefixcmp(ref->name, "refs/tags/")) {
		fprintf(stderr, "* %s: updating with %s\n",
			ref->name, note);
		show_new(type, ref->new_sha1);
		return s_update_ref("updating tag", ref, 0);
	}

	current = lookup_commit_reference_gently(ref->old_sha1, 1);
	updated = lookup_commit_reference_gently(ref->new_sha1, 1);
	if (!current || !updated) {
		char *msg;
		if (!strncmp(ref->name, "refs/tags/", 10))
			msg = "storing tag";
		else
			msg = "storing head";
		fprintf(stderr, "* %s: storing %s\n",
			ref->name, note);
		show_new(type, ref->new_sha1);
		return s_update_ref(msg, ref, 0);
	}

	strcpy(oldh, find_unique_abbrev(current->object.sha1, DEFAULT_ABBREV));
	strcpy(newh, find_unique_abbrev(ref->new_sha1, DEFAULT_ABBREV));

	if (in_merge_bases(current, &updated, 1)) {
		fprintf(stderr, "* %s: fast forward to %s\n",
			ref->name, note);
		fprintf(stderr, "  old..new: %s..%s\n", oldh, newh);
		return s_update_ref("fast forward", ref, 1);
	}
	if (!force && !ref->force) {
		fprintf(stderr,
			"* %s: not updating to non-fast forward %s\n",
			ref->name, note);
		fprintf(stderr,
			"  old...new: %s...%s\n", oldh, newh);
		return 1;
	}
	fprintf(stderr,
		"* %s: forcing update to non-fast forward %s\n",
		ref->name, note);
	fprintf(stderr, "  old...new: %s...%s\n", oldh, newh);
	return s_update_ref("forced-update", ref, 1);
}

static void store_updated_refs(const char *url, struct ref *ref_map)
{
	FILE *fp;
	struct commit *commit;
	int url_len, i, note_len;
	char note[1024];
	const char *what, *kind;
	struct ref *rm;
