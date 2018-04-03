			die("Couldn't look up commit object for HEAD");
	}
	for (i = 0; i < argc; i++, strbuf_release(&bname)) {
		strbuf_branchname(&bname, argv[i]);
		if (kinds == REF_LOCAL_BRANCH && !strcmp(head, bname.buf)) {
			error("Cannot delete the branch '%s' "
			      "which you are currently on.", bname.buf);
