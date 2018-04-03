
	for (i = 0; i < argc; i++) {
		struct object *o;

		o = peel_to_type(argv[i], 0, NULL, OBJ_COMMIT);
		if (!o)
			die("%s - not something we can merge", argv[i]);
		remotes = &commit_list_insert(lookup_commit(o->sha1),
			remotes)->next;

		strbuf_addf(&buf, "GITHEAD_%s", sha1_to_hex(o->sha1));
		setenv(buf.buf, argv[i], 1);
