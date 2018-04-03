		int flags = 0;

		strbuf_branchname(&bname, argv[i]);
		if (kinds == FILTER_REFS_BRANCHES && !strcmp(head, bname.buf)) {
			error(_("Cannot delete the branch '%s' "
			      "which you are currently on."), bname.buf);
			ret = 1;
