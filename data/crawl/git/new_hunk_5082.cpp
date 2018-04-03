	if (quoted) {
		free(*argv);
		*argv = NULL;
		return -SPLIT_CMDLINE_UNCLOSED_QUOTE;
	}

	ALLOC_GROW(*argv, count+1, size);
