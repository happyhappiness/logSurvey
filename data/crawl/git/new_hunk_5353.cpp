	return 0;
}

int notes_copy_from_stdin(int force)
{
	struct strbuf buf = STRBUF_INIT;
	struct notes_tree *t;
	int ret = 0;

	init_notes(NULL, NULL, NULL, 0);
	t = &default_notes_tree;

	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
		unsigned char from_obj[20], to_obj[20];
		struct strbuf **split;
		int err;

		split = strbuf_split(&buf, ' ');
		if (!split[0] || !split[1])
			die("Malformed input line: '%s'.", buf.buf);
		strbuf_rtrim(split[0]);
		strbuf_rtrim(split[1]);
		if (get_sha1(split[0]->buf, from_obj))
			die("Failed to resolve '%s' as a valid ref.", split[0]->buf);
		if (get_sha1(split[1]->buf, to_obj))
			die("Failed to resolve '%s' as a valid ref.", split[1]->buf);

		err = copy_note(t, from_obj, to_obj, force, combine_notes_overwrite);

		if (err) {
			error("Failed to copy notes from '%s' to '%s'",
			      split[0]->buf, split[1]->buf);
			ret = 1;
		}

		strbuf_list_free(split);
	}

	commit_notes(t, "Notes added by 'git notes copy'");
	free_notes(t);
	return ret;
}

int cmd_notes(int argc, const char **argv, const char *prefix)
{
	struct notes_tree *t;
