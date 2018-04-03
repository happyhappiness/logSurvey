		switch (opts->type) {
		case OPTION_ARGUMENT:
			break;
		case OPTION_INTEGER:
			if (opts->flags & PARSE_OPT_OPTARG)
				if (opts->long_name)
					pos += fprintf(stderr, "[=<n>]");
				else
					pos += fprintf(stderr, "[<n>]");
			else
				pos += fprintf(stderr, " <n>");
			break;
		case OPTION_CALLBACK:
			if (opts->flags & PARSE_OPT_NOARG)
				break;
			/* FALLTHROUGH */
		case OPTION_FILENAME:
			/* FALLTHROUGH */
		case OPTION_STRING:
