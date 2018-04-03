	return ret;
}

static struct notes_tree *init_notes_check(const char *subcommand)
{
	struct notes_tree *t;
	init_notes(NULL, NULL, NULL, 0);
	t = &default_notes_tree;

	if (prefixcmp(t->ref, "refs/notes/"))
		die("Refusing to %s notes in %s (outside of refs/notes/)",
		    subcommand, t->ref);
	return t;
}

static int list(int argc, const char **argv, const char *prefix)
{
	struct notes_tree *t;
	unsigned char object[20];
	const unsigned char *note;
	int retval = -1;
	struct option options[] = {
		OPT_END()
	};

	if (argc)
		argc = parse_options(argc, argv, prefix, options,
				     git_notes_list_usage, 0);

	if (1 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_list_usage, options);
	}

	t = init_notes_check("list");
	if (argc) {
		if (get_sha1(argv[0], object))
			die("Failed to resolve '%s' as a valid ref.", argv[0]);
		note = get_note(t, object);
		if (note) {
			puts(sha1_to_hex(note));
			retval = 0;
		} else
			retval = error("No note found for object %s.",
				       sha1_to_hex(object));
	} else
		retval = for_each_note(t, 0, list_each_note, NULL);

	free_notes(t);
	return retval;
}

static int add(int argc, const char **argv, const char *prefix)
{
	int retval = 0, force = 0;
	const char *object_ref;
	struct notes_tree *t;
	unsigned char object[20], new_note[20];
	char logmsg[100];
	const unsigned char *note;
	struct msg_arg msg = { 0, 0, STRBUF_INIT };
	struct option options[] = {
		{ OPTION_CALLBACK, 'm', "message", &msg, "MSG",
			"note contents as a string", PARSE_OPT_NONEG,
			parse_msg_arg},
		{ OPTION_CALLBACK, 'F', "file", &msg, "FILE",
			"note contents in a file", PARSE_OPT_NONEG,
			parse_file_arg},
		{ OPTION_CALLBACK, 'c', "reedit-message", &msg, "OBJECT",
			"reuse and edit specified note object", PARSE_OPT_NONEG,
			parse_reedit_arg},
		{ OPTION_CALLBACK, 'C', "reuse-message", &msg, "OBJECT",
			"reuse specified note object", PARSE_OPT_NONEG,
			parse_reuse_arg},
		OPT_BOOLEAN('f', "force", &force, "replace existing notes"),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_add_usage,
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

	create_note(object, &msg, 0, note, new_note);

	if (is_null_sha1(new_note))
		remove_note(t, object);
	else
		add_note(t, object, new_note, combine_notes_overwrite);

	snprintf(logmsg, sizeof(logmsg), "Notes %s by 'git notes %s'",
		 is_null_sha1(new_note) ? "removed" : "added", "add");
	commit_notes(t, logmsg);
out:
	free_notes(t);
	strbuf_release(&(msg.buf));
	return retval;
}

static int copy(int argc, const char **argv, const char *prefix)
{
	int retval = 0, force = 0, from_stdin = 0;
	const unsigned char *from_note, *note;
	const char *object_ref;
	unsigned char object[20], from_obj[20];
	struct notes_tree *t;
	const char *rewrite_cmd = NULL;
	struct option options[] = {
		OPT_BOOLEAN('f', "force", &force, "replace existing notes"),
		OPT_BOOLEAN(0, "stdin", &from_stdin, "read objects from stdin"),
		OPT_STRING(0, "for-rewrite", &rewrite_cmd, "command",
			   "load rewriting config for <command> (implies "
			   "--stdin)"),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_copy_usage,
			     0);

	if (from_stdin || rewrite_cmd) {
		if (argc) {
			error("too many parameters");
			usage_with_options(git_notes_copy_usage, options);
		} else {
			return notes_copy_from_stdin(force, rewrite_cmd);
		}
	}

	if (2 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_copy_usage, options);
	}

	if (get_sha1(argv[0], from_obj))
		die("Failed to resolve '%s' as a valid ref.", argv[0]);

	object_ref = 1 < argc ? argv[1] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check("copy");
	note = get_note(t, object);

	if (note) {
		if (!force) {
			retval = error("Cannot copy notes. Found existing "
				       "notes for object %s. Use '-f' to "
				       "overwrite existing notes",
				       sha1_to_hex(object));
			goto out;
		}
		fprintf(stderr, "Overwriting existing notes for object %s\n",
			sha1_to_hex(object));
	}

	from_note = get_note(t, from_obj);
	if (!from_note) {
		retval = error("Missing notes on source object %s. Cannot "
			       "copy.", sha1_to_hex(from_obj));
		goto out;
	}

	add_note(t, object, from_note, combine_notes_overwrite);
	commit_notes(t, "Notes added by 'git notes copy'");
out:
	free_notes(t);
	return retval;
}

static int append_edit(int argc, const char **argv, const char *prefix)
{
	const char *object_ref;
	struct notes_tree *t;
	unsigned char object[20], new_note[20];
	const unsigned char *note;
	char logmsg[100];
	const char * const *usage;
	struct msg_arg msg = { 0, 0, STRBUF_INIT };
	struct option options[] = {
		{ OPTION_CALLBACK, 'm', "message", &msg, "MSG",
			"note contents as a string", PARSE_OPT_NONEG,
			parse_msg_arg},
		{ OPTION_CALLBACK, 'F', "file", &msg, "FILE",
			"note contents in a file", PARSE_OPT_NONEG,
			parse_file_arg},
		{ OPTION_CALLBACK, 'c', "reedit-message", &msg, "OBJECT",
			"reuse and edit specified note object", PARSE_OPT_NONEG,
			parse_reedit_arg},
		{ OPTION_CALLBACK, 'C', "reuse-message", &msg, "OBJECT",
			"reuse specified note object", PARSE_OPT_NONEG,
			parse_reuse_arg},
		OPT_END()
	};
	int edit = !strcmp(argv[0], "edit");

	usage = edit ? git_notes_edit_usage : git_notes_append_usage;
	argc = parse_options(argc, argv, prefix, options, usage,
			     PARSE_OPT_KEEP_ARGV0);

	if (2 < argc) {
		error("too many parameters");
		usage_with_options(usage, options);
	}

	if (msg.given && edit)
		fprintf(stderr, "The -m/-F/-c/-C options have been deprecated "
			"for the 'edit' subcommand.\n"
			"Please use 'git notes add -f -m/-F/-c/-C' instead.\n");

	object_ref = 1 < argc ? argv[1] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check(argv[0]);
	note = get_note(t, object);

	create_note(object, &msg, !edit, note, new_note);

	if (is_null_sha1(new_note))
		remove_note(t, object);
	else
		add_note(t, object, new_note, combine_notes_overwrite);

	snprintf(logmsg, sizeof(logmsg), "Notes %s by 'git notes %s'",
		 is_null_sha1(new_note) ? "removed" : "added", argv[0]);
	commit_notes(t, logmsg);
	free_notes(t);
	strbuf_release(&(msg.buf));
	return 0;
}

static int show(int argc, const char **argv, const char *prefix)
{
	const char *object_ref;
	struct notes_tree *t;
	unsigned char object[20];
	const unsigned char *note;
	int retval;
	struct option options[] = {
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_show_usage,
			     0);

	if (1 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_show_usage, options);
	}

	object_ref = argc ? argv[0] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check("show");
	note = get_note(t, object);

	if (!note)
		retval = error("No note found for object %s.",
			       sha1_to_hex(object));
	else {
		const char *show_args[3] = {"show", sha1_to_hex(note), NULL};
		retval = execv_git_cmd(show_args);
	}
	free_notes(t);
	return retval;
}

static int remove_cmd(int argc, const char **argv, const char *prefix)
{
	struct option options[] = {
		OPT_END()
	};
	const char *object_ref;
	struct notes_tree *t;
	unsigned char object[20];

	argc = parse_options(argc, argv, prefix, options,
			     git_notes_remove_usage, 0);

	if (1 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_remove_usage, options);
	}

	object_ref = argc ? argv[0] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check("remove");

	fprintf(stderr, "Removing note for object %s\n", sha1_to_hex(object));
	remove_note(t, object);

	commit_notes(t, "Notes removed by 'git notes remove'");
	free_notes(t);
	return 0;
}

static int prune(int argc, const char **argv, const char *prefix)
{
	struct notes_tree *t;
	struct option options[] = {
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_prune_usage,
			     0);

	if (argc) {
		error("too many parameters");
		usage_with_options(git_notes_prune_usage, options);
	}

	t = init_notes_check("prune");

	prune_notes(t);
	commit_notes(t, "Notes removed by 'git notes prune'");
	free_notes(t);
	return 0;
}

int cmd_notes(int argc, const char **argv, const char *prefix)
{
	int result;
	const char *override_notes_ref = NULL;
	struct option options[] = {
		OPT_STRING(0, "ref", &override_notes_ref, "notes_ref",
			   "use notes from <notes_ref>"),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, options, git_notes_usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	if (override_notes_ref) {
		struct strbuf sb = STRBUF_INIT;
		if (!prefixcmp(override_notes_ref, "refs/notes/"))
			/* we're happy */;
		else if (!prefixcmp(override_notes_ref, "notes/"))
			strbuf_addstr(&sb, "refs/");
		else
			strbuf_addstr(&sb, "refs/notes/");
		strbuf_addstr(&sb, override_notes_ref);
		setenv("GIT_NOTES_REF", sb.buf, 1);
		strbuf_release(&sb);
	}

	if (argc < 1 || !strcmp(argv[0], "list"))
		result = list(argc, argv, prefix);
	else if (!strcmp(argv[0], "add"))
		result = add(argc, argv, prefix);
	else if (!strcmp(argv[0], "copy"))
		result = copy(argc, argv, prefix);
	else if (!strcmp(argv[0], "append") || !strcmp(argv[0], "edit"))
		result = append_edit(argc, argv, prefix);
	else if (!strcmp(argv[0], "show"))
		result = show(argc, argv, prefix);
	else if (!strcmp(argv[0], "remove"))
		result = remove_cmd(argc, argv, prefix);
	else if (!strcmp(argv[0], "prune"))
		result = prune(argc, argv, prefix);
	else {
		result = error("Unknown subcommand: %s", argv[0]);
		usage_with_options(git_notes_usage, options);
	}

	return result ? 1 : 0;
}
