	if (!editor)
		editor = "vi";

	if (strcmp(editor, ":")) {
		const char *args[] = { editor, path, NULL };

		if (run_command_v_opt(args, 0))
			die("There was a problem with the editor %s.", editor);
	}

	if (strbuf_read_file(buffer, path, 0) < 0)
		die("could not read message file '%s': %s",