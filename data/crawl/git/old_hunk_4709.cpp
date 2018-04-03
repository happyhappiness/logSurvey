		remote = "";
		break;
	default:
		die("cannot use -a with -d");
	}

	if (!force) {
		head_rev = lookup_commit_reference(head_sha1);
		if (!head_rev)
			die("Couldn't look up commit object for HEAD");
	}
	for (i = 0; i < argc; i++, strbuf_release(&bname)) {
		strbuf_branchname(&bname, argv[i]);
		if (kinds == REF_LOCAL_BRANCH && !strcmp(head, bname.buf)) {
			error("Cannot delete the branch '%s' "
			      "which you are currently on.", bname.buf);
			ret = 1;
			continue;
		}
