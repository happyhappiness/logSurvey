	if (depth)
		set_option(TRANS_OPT_DEPTH, depth);

	if (argc > 1) {
		int j = 0;
		refs = xcalloc(argc + 1, sizeof(const char *));
