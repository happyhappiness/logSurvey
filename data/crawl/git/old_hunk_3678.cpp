
	if (!strcmp(data->refname, entry->name))
		return 0;
	if (!ref_resolves_to_object(entry))
		return 0; /* Skip broken refs */
	len = snprintf(line, sizeof(line), "%s %s\n",
		       sha1_to_hex(entry->u.value.sha1), entry->name);
	/* this should not happen but just being defensive */
