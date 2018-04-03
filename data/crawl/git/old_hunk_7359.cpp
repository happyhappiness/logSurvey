			pos += fprintf(stderr, "--%s", opts->long_name);

		switch (opts->type) {
		case OPTION_INTEGER:
			if (opts->flags & PARSE_OPT_OPTARG)
				pos += fprintf(stderr, " [<n>]");
