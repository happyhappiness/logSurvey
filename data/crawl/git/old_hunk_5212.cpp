			s = literal ? "[%s]" : "[<%s>]";
	else
		s = literal ? " %s" : " <%s>";
	return fprintf(stderr, s, opts->argh ? opts->argh : "...");
}

#define USAGE_OPTS_WIDTH 24
#define USAGE_GAP         2

static int usage_with_options_internal(const char * const *usagestr,
				const struct option *opts, int full)
{
	if (!usagestr)
		return PARSE_OPT_HELP;

	fprintf(stderr, "usage: %s\n", *usagestr++);
	while (*usagestr && **usagestr)
		fprintf(stderr, "   or: %s\n", *usagestr++);
	while (*usagestr) {
		fprintf(stderr, "%s%s\n",
				**usagestr ? "    " : "",
				*usagestr);
		usagestr++;
	}

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
		if (!full && (opts->flags & PARSE_OPT_HIDDEN))
			continue;

		pos = fprintf(stderr, "    ");
		if (opts->short_name && !(opts->flags & PARSE_OPT_NEGHELP)) {
			if (opts->flags & PARSE_OPT_NODASH)
				pos += fprintf(stderr, "%c", opts->short_name);
			else
				pos += fprintf(stderr, "-%c", opts->short_name);
		}
		if (opts->long_name && opts->short_name)
			pos += fprintf(stderr, ", ");
		if (opts->long_name)
			pos += fprintf(stderr, "--%s%s",
				(opts->flags & PARSE_OPT_NEGHELP) ?  "no-" : "",
				opts->long_name);
		if (opts->type == OPTION_NUMBER)
			pos += fprintf(stderr, "-NUM");

		if (!(opts->flags & PARSE_OPT_NOARG))
			pos += usage_argh(opts);

		if (pos <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pos;
		else {
			fputc('\n', stderr);
			pad = USAGE_OPTS_WIDTH;
		}
		fprintf(stderr, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
	}
	fputc('\n', stderr);

	return PARSE_OPT_HELP;
}

void usage_with_options(const char * const *usagestr,
			const struct option *opts)
{
	usage_with_options_internal(usagestr, opts, 0);
	exit(129);
}

