static int for_each_replace_name(const char **argv, each_replace_name_fn fn)
{
	const char **p, *full_hex;
	char ref[PATH_MAX];
	int had_error = 0;
	struct object_id oid;

	for (p = argv; *p; p++) {
		if (get_oid(*p, &oid)) {
			error("Failed to resolve '%s' as a valid ref.", *p);
			had_error = 1;
			continue;
		}
		full_hex = oid_to_hex(&oid);
		snprintf(ref, sizeof(ref), "%s%s", git_replace_ref_base, full_hex);
		/* read_ref() may reuse the buffer */
		full_hex = ref + strlen(git_replace_ref_base);
		if (read_ref(ref, oid.hash)) {
			error("replace ref '%s' not found.", full_hex);
			had_error = 1;
			continue;
		}
		if (fn(full_hex, ref, &oid))
			had_error = 1;
	}
	return had_error;
