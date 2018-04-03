		return list_tags(argv[0], lines == -1 ? 0 : lines,
				 with_commit);
	if (lines != -1)
		die("-n option is only allowed with -l.");
	if (with_commit)
		die("--contains option is only allowed with -l.");
	if (delete)
		return for_each_tag_name(argv, delete_tag);
	if (verify)
		return for_each_tag_name(argv, verify_tag);

	if (msg.given || msgfile) {
		if (msg.given && msgfile)
			die("only one -F or -m option is allowed.");
		annotate = 1;
		if (msg.given)
			strbuf_addbuf(&buf, &(msg.buf));
		else {
			if (!strcmp(msgfile, "-")) {
				if (strbuf_read(&buf, 0, 1024) < 0)
					die_errno("cannot read '%s'", msgfile);
			} else {
				if (strbuf_read_file(&buf, msgfile, 1024) < 0)
					die_errno("could not open or read '%s'",
						msgfile);
			}
		}
