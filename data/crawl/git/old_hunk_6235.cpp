	 * Fetch a copy of the object if it doesn't exist locally - it
	 * may be required for updating server info later.
	 */
	if (remote->can_update_info_refs && !has_sha1_file(ref->old_sha1)) {
		obj = lookup_unknown_object(ref->old_sha1);
		if (obj) {
			fprintf(stderr,	"  fetch %s for %s\n",
