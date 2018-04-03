		die(_("No remote repository specified.  Please, specify either a URL or a\n"
		    "remote name from which new revisions should be fetched."));

	gtransport = prepare_transport(remote);
	if (argc > 0) {
		int j = 0;
		refs = xcalloc(argc + 1, sizeof(const char *));