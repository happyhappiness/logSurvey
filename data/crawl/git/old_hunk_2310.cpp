	if (!mkdtemp(mtime_dir.buf))
		die_errno("Could not make temporary directory");

	fprintf(stderr, _("Testing "));
	atexit(remove_test_directory);
	xstat_mtime_dir(&st);
	fill_stat_data(&base, &st);
