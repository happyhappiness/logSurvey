		switch (opts->type) {
		case OPTION_ARGUMENT:
			break;
		case OPTION_CALLBACK:
			if (opts->flags & PARSE_OPT_NOARG)
				break;
			/* FALLTHROUGH */
		case OPTION_INTEGER:
			/* FALLTHROUGH */
		case OPTION_FILENAME:
			/* FALLTHROUGH */
		case OPTION_STRING:
