		if (opts->long_name && opts->short_name)
			pos += fprintf(stderr, ", ");
		if (opts->long_name)
			pos += fprintf(stderr, "--%s", opts->long_name);
		if (opts->type == OPTION_NUMBER)
			pos += fprintf(stderr, "-NUM");

