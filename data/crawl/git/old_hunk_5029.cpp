		const char *prog;
		char *full_cmd;
		char *rawargs;
		const char **argv;
		int code;

		fprintf(stderr, "git> ");
		if (strbuf_getline(&line, stdin, '\n') == EOF) {
