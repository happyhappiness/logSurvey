	init_revisions(&revs, prefix);

	argc = parse_options(argc, argv, options, prune_usage, 0);
	while (argc--) {
		unsigned char sha1[20];
		const char *name = *argv++;

		if (!get_sha1(name, sha1)) {
			struct object *object = parse_object(sha1);
			if (!object)
				die("bad object: %s", name);
			add_pending_object(&revs, object, "");
		}
		else
			die("unrecognized argument: %s", name);
	}
	mark_reachable_objects(&revs, 1);
	prune_object_dir(get_object_directory());

