	return 0;
}

static int update_local_ref(struct ref *ref,
			    const char *note,
			    int verbose)
{
	char oldh[41], newh[41];
	struct commit *current = NULL, *updated;
	enum object_type type;
	struct branch *current_branch = branch_get(NULL);

	type = sha1_object_info(ref->new_sha1, NULL);
	if (type < 0)
		die("object %s not found", sha1_to_hex(ref->new_sha1));

	if (!*ref->name) {
		/* Not storing */
		if (verbose) {
			fprintf(stderr, "* fetched %s\n", note);
			show_new(type, ref->new_sha1);
		}
		return 0;
	}

	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
		if (verbose) {
			fprintf(stderr, "* %s: same as %s\n",
				ref->name, note);
			show_new(type, ref->new_sha1);
		}
		return 0;
	}

