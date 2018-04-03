	return 0;
}

static int replace_object(const char *object_ref, const char *replace_ref,
			  int force)
{
	unsigned char object[20], prev[20], repl[20];
	char ref[PATH_MAX];
	struct ref_lock *lock;

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);
	if (get_sha1(replace_ref, repl))
		die("Failed to resolve '%s' as a valid ref.", replace_ref);

	if (snprintf(ref, sizeof(ref),
		     "refs/replace/%s",
		     sha1_to_hex(object)) > sizeof(ref) - 1)
		die("replace ref name too long: %.*s...", 50, ref);
	if (check_ref_format(ref))
		die("'%s' is not a valid ref name.", ref);

	if (!resolve_ref(ref, prev, 1, NULL))
		hashclr(prev);
	else if (!force)
		die("replace ref '%s' already exists", ref);

	lock = lock_any_ref_for_update(ref, prev, 0);
	if (!lock)
		die("%s: cannot lock the ref", ref);
	if (write_ref_sha1(lock, repl, NULL) < 0)
		die("%s: cannot update the ref", ref);

	return 0;
}

int cmd_replace(int argc, const char **argv, const char *prefix)
{
	int list = 0, delete = 0, force = 0;
	struct option options[] = {
		OPT_BOOLEAN('l', NULL, &list, "list replace refs"),
		OPT_BOOLEAN('d', NULL, &delete, "delete replace refs"),
		OPT_BOOLEAN('f', NULL, &force, "replace the ref if it exists"),
		OPT_END()
	};

