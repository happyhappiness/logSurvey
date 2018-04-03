	return 0;
}

/*
 * If entry is no longer needed in packed-refs, add it to the string
 * list pointed to by cb_data.  Reasons for deleting entries:
 *
 * - Entry is broken.
 * - Entry is overridden by a loose ref.
 * - Entry does not point at a valid object.
 *
 * In the first and third cases, also emit an error message because these
 * are indications of repository corruption.
 */
static int curate_packed_ref_fn(struct ref_entry *entry, void *cb_data)
{
	struct string_list *refs_to_delete = cb_data;

	if (entry->flag & REF_ISBROKEN) {
		/* This shouldn't happen to packed refs. */
		error("%s is broken!", entry->name);
		string_list_append(refs_to_delete, entry->name);
		return 0;
	}
	if (!has_sha1_file(entry->u.value.sha1)) {
