
	for (i = 0; i < argc; i++) {
		struct object *o;
		struct commit *commit;

		o = peel_to_type(argv[i], 0, NULL, OBJ_COMMIT);
		if (!o)
			die("%s - not something we can merge", argv[i]);
		commit = lookup_commit(o->sha1);
		commit->util = (void *)argv[i];
		remotes = &commit_list_insert(commit, remotes)->next;

		strbuf_addf(&buf, "GITHEAD_%s", sha1_to_hex(o->sha1));
		setenv(buf.buf, argv[i], 1);
