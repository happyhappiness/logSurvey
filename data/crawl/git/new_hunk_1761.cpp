	char *data = NULL;

	if (diff_populate_filespec(spec, 0))
		die("Cannot read blob %s", oid_to_hex(&spec->oid));

	ALLOC_ARRAY(ends, size);
	ends[cur++] = 0;
