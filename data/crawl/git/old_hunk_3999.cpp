
	if (strcmp(editor, ":")) {
		const char *args[] = { editor, path, NULL };

		if (run_command_v_opt_cd_env(args, RUN_USING_SHELL, NULL, env))
			return error("There was a problem with the editor '%s'.",
					editor);
	}