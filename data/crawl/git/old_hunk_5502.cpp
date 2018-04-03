		editor = getenv("EDITOR");

	if (!editor && terminal_is_dumb)
		return error("terminal is dumb, but EDITOR unset");

	if (!editor)
		editor = "vi";

	if (strcmp(editor, ":")) {
		size_t len = strlen(editor);
		int i = 0;
