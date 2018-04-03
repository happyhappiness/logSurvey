
	check_mergetags(commit, argc, argv);

	if (write_object_file(buf.buf, buf.len, commit_type, &new))
		die(_("could not write replacement commit for: '%s'"), old_ref);

	strbuf_release(&buf);
