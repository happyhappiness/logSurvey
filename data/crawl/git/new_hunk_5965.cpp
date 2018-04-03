		if (opts->type == OPTION_NUMBER)
			pos += fprintf(stderr, "-NUM");

		if (!(opts->flags & PARSE_OPT_NOARG))
			pos += usage_argh(opts);

		if (pos <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pos;
