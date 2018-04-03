	return -1;
}

static int do_one_ref(const char *base, each_ref_fn fn, int trim,
		      void *cb_data, struct ref_list *entry)
{
	if (strncmp(base, entry->name, trim))
		return 0;
	if (is_null_sha1(entry->sha1))
		return 0;
	if (!has_sha1_file(entry->sha1)) {
		error("%s does not point to a valid object!", entry->name);
		return 0;
	}
	current_ref = entry;
	return fn(entry->name + trim, entry->sha1, entry->flag, cb_data);
