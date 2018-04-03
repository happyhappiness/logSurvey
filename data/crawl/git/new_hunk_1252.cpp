			die(_("Couldn't look up commit object for HEAD"));
	}
	for (i = 0; i < argc; i++, strbuf_release(&bname)) {
		char *target = NULL;
		int flags = 0;

		strbuf_branchname(&bname, argv[i]);
