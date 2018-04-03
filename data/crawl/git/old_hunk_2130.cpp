	if (verbose)
		flags |= GPG_VERIFY_VERBOSE;

	while (i < argc)
		if (verify_tag(argv[i++], flags))
			had_error = 1;
	return had_error;
}