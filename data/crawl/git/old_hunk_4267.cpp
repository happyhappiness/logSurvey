	return result;
}

static int is_refname_available(const char *ref, const char *oldref,
				struct ref_array *array, int quiet)
{
	int i, namlen = strlen(ref); /* e.g. 'foo/bar' */
	for (i = 0; i < array->nr; i++ ) {
		struct ref_entry *entry = array->refs[i];
		/* entry->name could be 'foo' or 'foo/bar/baz' */
		if (!oldref || strcmp(oldref, entry->name)) {
			int len = strlen(entry->name);
			int cmplen = (namlen < len) ? namlen : len;
			const char *lead = (namlen < len) ? entry->name : ref;
			if (!strncmp(ref, entry->name, cmplen) &&
			    lead[cmplen] == '/') {
				if (!quiet)
					error("'%s' exists; cannot create '%s'",
					      entry->name, ref);
				return 0;
			}
		}
