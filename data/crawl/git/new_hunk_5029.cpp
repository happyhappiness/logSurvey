		const char *prog;
		char *full_cmd;
		char *rawargs;
		char *split_args;
		const char **argv;
		int code;
		int count;

		fprintf(stderr, "git> ");
		if (strbuf_getline(&line, stdin, '\n') == EOF) {
