
	if (strcmp(editor, ":")) {
		const char *args[] = { editor, path, NULL };
		struct child_process p;

		memset(&p, 0, sizeof(p));
		p.argv = args;
		p.env = env;
		p.use_shell = 1;
		if (start_command(&p) < 0)
			return error("unable to start editor '%s'", editor);

		if (finish_command(&p))
			return error("There was a problem with the editor '%s'.",
					editor);
	}