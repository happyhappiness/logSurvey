	char *data = NULL;

	if (diff_populate_filespec(spec, 0))
		die("Cannot read blob %s", sha1_to_hex(spec->sha1));

	ALLOC_ARRAY(ends, size);
	ends[cur++] = 0;
