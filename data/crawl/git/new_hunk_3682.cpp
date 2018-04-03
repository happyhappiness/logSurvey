	if (prefixcmp(entry->name, base))
		return 0;

	if (!(flags & DO_FOR_EACH_INCLUDE_BROKEN) &&
	      !ref_resolves_to_object(entry))
		return 0;

	current_ref = entry;
	retval = fn(entry->name + trim, entry->u.value.sha1, entry->flag, cb_data);
	current_ref = NULL;