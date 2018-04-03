		if (opts->type == OPTION_NUMBER)
			pos += fprintf(stderr, "-NUM");

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
			if (opts->argh)
				pos += usage_argh(opts);
			else {
				if (opts->flags & PARSE_OPT_OPTARG)
					if (opts->long_name)
						pos += fprintf(stderr, "[=...]");
					else
						pos += fprintf(stderr, "[...]");
				else
					pos += fprintf(stderr, " ...");
			}
			break;
		default: /* OPTION_{BIT,BOOLEAN,NUMBER,SET_INT,SET_PTR} */
			break;
		}

		if (pos <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pos;
