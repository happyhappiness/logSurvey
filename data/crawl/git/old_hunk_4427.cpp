			     0);

	if (1 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_add_usage, options);
	}

	object_ref = argc ? argv[0] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check("add");
	note = get_note(t, object);

	if (note) {
		if (!force) {
			retval = error("Cannot add notes. Found existing notes "
				       "for object %s. Use '-f' to overwrite "
				       "existing notes", sha1_to_hex(object));
			goto out;
		}
		fprintf(stderr, "Overwriting existing notes for object %s\n",
			sha1_to_hex(object));
	}

