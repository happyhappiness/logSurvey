		editor = getenv("EDITOR");

	terminal = getenv("TERM");
	if (!editor && (!terminal || !strcmp(terminal, "dumb"))) {
		fprintf(stderr,
		"Terminal is dumb but no VISUAL nor EDITOR defined.\n"
		"Please supply the message using either -m or -F option.\n");
		exit(1);
	}

	if (!editor)
		editor = "vi";

	if (strcmp(editor, ":")) {
		size_t len = strlen(editor);
		int i = 0;
		const char *args[6];
		struct strbuf arg0;

