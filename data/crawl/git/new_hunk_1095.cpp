	else if (flags & GET_SHA1_BLOB)
		ds.fn = disambiguate_blob_only;

	find_short_object_filename(&ds);
	find_short_packed_object(&ds);
	status = finish_object_disambiguation(&ds, sha1);

	if (!quietly && (status == SHORT_NAME_AMBIGUOUS))
		return error("short SHA1 %.*s is ambiguous.", ds.len, ds.hex_pfx);
	return status;
}

int for_each_abbrev(const char *prefix, each_abbrev_fn fn, void *cb_data)
{
	struct disambiguate_state ds;

	if (init_object_disambiguation(prefix, strlen(prefix), &ds) < 0)
		return -1;

	ds.always_call_fn = 1;
	ds.cb_data = cb_data;
	ds.fn = fn;

	find_short_object_filename(&ds);
	find_short_packed_object(&ds);
	return ds.ambiguous;
}
