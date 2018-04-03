		editor = getenv("EDITOR");

	terminal = getenv("TERM");
	if (!editor && (!terminal || !strcmp(terminal, "dumb")))
		return error("Terminal is dumb but no VISUAL nor EDITOR defined.");

	if (!editor)
		editor = "vi";

	if (strcmp(editor, ":")) {
		size_t len = strlen(editor);
		int i = 0;
		int failed;
		const char *args[6];
		struct strbuf arg0;

