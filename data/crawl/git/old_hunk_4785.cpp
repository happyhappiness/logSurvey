		return fd;
	}

	fprintf(stderr, "What does '%s' for GIT_TRACE mean?\n", trace);
	fprintf(stderr, "If you want to trace into a file, "
		"then please set GIT_TRACE to an absolute pathname "
		"(starting with /).\n");
	fprintf(stderr, "Defaulting to tracing on stderr...\n");

	return STDERR_FILENO;
