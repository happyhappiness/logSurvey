	return 0;
}

static int repack_ref_fn(struct ref_entry *entry, void *cb_data)
{
	int *fd = cb_data;
	enum peel_status peel_status;

	if (entry->flag & REF_ISBROKEN) {
		/* This shouldn't happen to packed refs. */
		error("%s is broken!", entry->name);
		return 0;
	}
	if (!has_sha1_file(entry->u.value.sha1)) {
