
	check_mergetags(commit, argc, argv);

	if (write_sha1_file(buf.buf, buf.len, commit_type, new.hash))
		die(_("could not write replacement commit for: '%s'"), old_ref);

	strbuf_release(&buf);