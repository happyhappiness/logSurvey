void usage_with_options(const char * const *usagestr,
                        const struct option *opts)
{
	fprintf(stderr, "usage: %s\n", *usagestr++);
	while (*usagestr && **usagestr)
		fprintf(stderr, "   or: %s\n", *usagestr++);
	while (*usagestr)
		fprintf(stderr, "    %s\n", *usagestr++);

	if (opts->type != OPTION_GROUP)
		fputc('\n', stderr);

	for (; opts->type != OPTION_END; opts++) {
		size_t pos;
		int pad;

		if (opts->type == OPTION_GROUP) {
			fputc('\n', stderr);
			if (*opts->help)
				fprintf(stderr, "%s\n", opts->help);
			continue;
		}

		pos = fprintf(stderr, "    ");
		if (opts->short_name)
			pos += fprintf(stderr, "-%c", opts->short_name);
		if (opts->long_name && opts->short_name)
			pos += fprintf(stderr, ", ");
		if (opts->long_name)
			pos += fprintf(stderr, "--%s", opts->long_name);

		switch (opts->type) {
		case OPTION_INTEGER:
			pos += fprintf(stderr, " <n>");
			break;
		case OPTION_STRING:
			if (opts->argh)
				pos += fprintf(stderr, " <%s>", opts->argh);
			else
				pos += fprintf(stderr, " ...");
			break;
		default:
			break;
		}

		if (pos <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pos;
		else {
			fputc('\n', stderr);
			pad = USAGE_OPTS_WIDTH;
		}
		fprintf(stderr, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
	}
	fputc('\n', stderr);

	exit(129);
}