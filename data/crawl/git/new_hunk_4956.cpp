	return retval;
}

static int merge(int argc, const char **argv, const char *prefix)
{
	struct strbuf remote_ref = STRBUF_INIT, msg = STRBUF_INIT;
	unsigned char result_sha1[20];
	struct notes_merge_options o;
	int verbosity = 0, result;
	struct option options[] = {
		OPT__VERBOSITY(&verbosity),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options,
			     git_notes_merge_usage, 0);

	if (argc != 1) {
		error("Must specify a notes ref to merge");
		usage_with_options(git_notes_merge_usage, options);
	}

	init_notes_merge_options(&o);
	o.verbosity = verbosity + NOTES_MERGE_VERBOSITY_DEFAULT;

	o.local_ref = default_notes_ref();
	strbuf_addstr(&remote_ref, argv[0]);
	expand_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	result = notes_merge(&o, result_sha1);

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
		    remote_ref.buf, default_notes_ref());
	if (result == 0) { /* Merge resulted (trivially) in result_sha1 */
		/* Update default notes ref with new commit */
		update_ref(msg.buf, default_notes_ref(), result_sha1, NULL,
			   0, DIE_ON_ERR);
	} else {
		/* TODO: */
		die("'git notes merge' cannot yet handle non-trivial merges!");
	}

	strbuf_release(&remote_ref);
	strbuf_release(&msg);
	return 0;
}

static int remove_cmd(int argc, const char **argv, const char *prefix)
{
	struct option options[] = {
