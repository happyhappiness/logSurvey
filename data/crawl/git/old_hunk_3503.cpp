		die(_("No remote repository specified.  Please, specify either a URL or a\n"
		    "remote name from which new revisions should be fetched."));

	gtransport = transport_get(remote, NULL);
	transport_set_verbosity(gtransport, verbosity, progress);
	if (upload_pack)
		set_option(TRANS_OPT_UPLOADPACK, upload_pack);
	if (keep)
		set_option(TRANS_OPT_KEEP, "yes");
	if (depth)
		set_option(TRANS_OPT_DEPTH, depth);

	if (argc > 0) {
		int j = 0;
		refs = xcalloc(argc + 1, sizeof(const char *));