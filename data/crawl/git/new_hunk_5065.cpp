		die("could not chdir to user's home directory");
}

static void run_shell(void)
{
	int done = 0;
	static const char *help_argv[] = { HELP_COMMAND, NULL };
	/* Print help if enabled */
	run_command_v_opt(help_argv, RUN_SILENT_EXEC_FAILURE);

	do {
		struct strbuf line = STRBUF_INIT;
		const char *prog;
		char *full_cmd;
		char *rawargs;
		const char **argv;
		int code;

		fprintf(stderr, "git> ");
		if (strbuf_getline(&line, stdin, '\n') == EOF) {
			fprintf(stderr, "\n");
			strbuf_release(&line);
			break;
		}
		strbuf_trim(&line);
		rawargs = strbuf_detach(&line, NULL);
		if (split_cmdline(rawargs, &argv) == -1) {
			free(rawargs);
			continue;
		}

		prog = argv[0];
		if (!strcmp(prog, "")) {
		} else if (!strcmp(prog, "quit") || !strcmp(prog, "logout") ||
			   !strcmp(prog, "exit") || !strcmp(prog, "bye")) {
			done = 1;
		} else if (is_valid_cmd_name(prog)) {
			full_cmd = make_cmd(prog);
			argv[0] = full_cmd;
			code = run_command_v_opt(argv, RUN_SILENT_EXEC_FAILURE);
			if (code == -1 && errno == ENOENT) {
				fprintf(stderr, "unrecognized command '%s'\n", prog);
			}
			free(full_cmd);
		} else {
			fprintf(stderr, "invalid command format '%s'\n", prog);
		}

		free(argv);
		free(rawargs);
	} while (!done);
}

static struct commands {
	const char *name;
	int (*exec)(const char *me, char *arg);
