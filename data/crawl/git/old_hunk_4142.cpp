			builtin_merge_options);

	strbuf_addstr(&buf, "merge");
	for (i = 0; i < argc; i++)
		strbuf_addf(&buf, " %s", argv[i]);
	setenv("GIT_REFLOG_ACTION", buf.buf, 0);
	strbuf_reset(&buf);

	for (i = 0; i < argc; i++) {
		struct commit *commit = get_merge_parent(argv[i]);
		if (!commit)
			die(_("%s - not something we can merge"), argv[i]);
		remotes = &commit_list_insert(commit, remotes)->next;
		strbuf_addf(&buf, "GITHEAD_%s",
			    sha1_to_hex(commit->object.sha1));
		setenv(buf.buf, argv[i], 1);
		strbuf_reset(&buf);
		if (!fast_forward_only &&
		    merge_remote_util(commit) &&