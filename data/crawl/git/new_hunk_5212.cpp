			s = literal ? "[%s]" : "[<%s>]";
	else
		s = literal ? " %s" : " <%s>";
	return fprintf(outfile, s, opts->argh ? opts->argh : "...");
}

#define USAGE_OPTS_WIDTH 24
#define USAGE_GAP         2

static int usage_with_options_internal(const char * const *usagestr,
				const struct option *opts, int full, int err)
{
	FILE *outfile = err ? stderr : stdout;

	if (!usagestr)
		return PARSE_OPT_HELP;

	fprintf(outfile, "usage: %s\n", *usagestr++);
	while (*usagestr && **usagestr)
		fprintf(outfile, "   or: %s\n", *usagestr++);
	while (*usagestr) {
		fprintf(outfile, "%s%s\n",
				**usagestr ? "    " : "",
				*usagestr);
		usagestr++;
	}

	if (opts->type != OPTION_GROUP)
		fputc('\n', outfile);

	for (; opts->type != OPTION_END; opts++) {
		size_t pos;
		int pad;

		if (opts->type == OPTION_GROUP) {
			fputc('\n', outfile);
			if (*opts->help)
				fprintf(outfile, "%s\n", opts->help);
			continue;
		}
		if (!full && (opts->flags & PARSE_OPT_HIDDEN))
			continue;

		pos = fprintf(outfile, "    ");
		if (opts->short_name && !(opts->flags & PARSE_OPT_NEGHELP)) {
			if (opts->flags & PARSE_OPT_NODASH)
				pos += fprintf(outfile, "%c", opts->short_name);
			else
				pos += fprintf(outfile, "-%c", opts->short_name);
		}
		if (opts->long_name && opts->short_name)
			pos += fprintf(outfile, ", ");
		if (opts->long_name)
			pos += fprintf(outfile, "--%s%s",
				(opts->flags & PARSE_OPT_NEGHELP) ?  "no-" : "",
				opts->long_name);
		if (opts->type == OPTION_NUMBER)
			pos += fprintf(outfile, "-NUM");

		if (!(opts->flags & PARSE_OPT_NOARG))
			pos += usage_argh(opts, outfile);

		if (pos <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pos;
		else {
			fputc('\n', outfile);
			pad = USAGE_OPTS_WIDTH;
		}
		fprintf(outfile, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
	}
	fputc('\n', outfile);

	return PARSE_OPT_HELP;
}

void usage_with_options(const char * const *usagestr,
			const struct option *opts)
{
	usage_with_options_internal(usagestr, opts, 0, 1);
	exit(129);
}

