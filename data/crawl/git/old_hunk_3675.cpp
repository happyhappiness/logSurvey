	return lock_ref_sha1_basic(refname, old_sha1, flags, NULL);
}

static int repack_ref_fn(struct ref_entry *entry, void *cb_data)
{
	int *fd = cb_data;
	char line[PATH_MAX + 100];
	int len;

	if (entry->flag & REF_ISBROKEN) {
		/* This shouldn't happen to packed refs. */
		error("%s is broken!", entry->name);
