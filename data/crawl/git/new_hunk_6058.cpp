			pos += fprintf(stderr, ", ");
		if (opts->long_name)
			pos += fprintf(stderr, "--%s", opts->long_name);
		if (opts->type == OPTION_NUMBER)
			pos += fprintf(stderr, "-NUM");

		switch (opts->type) {
		case OPTION_ARGUMENT:
