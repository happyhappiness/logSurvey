
static int for_each_replace_name(const char **argv, each_replace_name_fn fn)
{
	const char **p;
	char ref[PATH_MAX];
	int had_error = 0;
	unsigned char sha1[20];

	for (p = argv; *p; p++) {
		if (snprintf(ref, sizeof(ref), "refs/replace/%s", *p)
					>= sizeof(ref)) {
			error("replace ref name too long: %.*s...", 50, *p);
			had_error = 1;
			continue;
		}
		if (read_ref(ref, sha1)) {
			error("replace ref '%s' not found.", *p);
			had_error = 1;
			continue;
		}
		if (fn(*p, ref, sha1))
			had_error = 1;
	}
	return had_error;
