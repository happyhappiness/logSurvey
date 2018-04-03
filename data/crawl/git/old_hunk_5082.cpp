	if (quoted) {
		free(*argv);
		*argv = NULL;
		return error("unclosed quote");
	}

	ALLOC_GROW(*argv, count+1, size);
