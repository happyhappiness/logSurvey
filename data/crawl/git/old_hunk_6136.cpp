			die("Couldn't look up commit object for HEAD");
	}
	for (i = 0; i < argc; i++, strbuf_release(&bname)) {
		int len = strlen(argv[i]);

		if (interpret_nth_last_branch(argv[i], &bname) != len)
			strbuf_add(&bname, argv[i], len);

		if (kinds == REF_LOCAL_BRANCH && !strcmp(head, bname.buf)) {
			error("Cannot delete the branch '%s' "
			      "which you are currently on.", bname.buf);
