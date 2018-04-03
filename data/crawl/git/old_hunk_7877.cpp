void usage_with_options(const char * const *usagestr,
                        const struct option *opts)
{
	struct strbuf sb;

	strbuf_init(&sb, 4096);
	strbuf_addstr(&sb, *usagestr);
	strbuf_addch(&sb, '\n');
	while (*++usagestr)
		strbuf_addf(&sb, "    %s\n", *usagestr);

	if (opts->type != OPTION_GROUP)
		strbuf_addch(&sb, '\n');

	for (; opts->type != OPTION_END; opts++) {
		size_t pos;
		int pad;

		if (opts->type == OPTION_GROUP) {
			strbuf_addch(&sb, '\n');
			if (*opts->help)
				strbuf_addf(&sb, "%s\n", opts->help);
			continue;
		}

		pos = sb.len;
		strbuf_addstr(&sb, "    ");
		if (opts->short_name)
			strbuf_addf(&sb, "-%c", opts->short_name);
		if (opts->long_name && opts->short_name)
			strbuf_addstr(&sb, ", ");
		if (opts->long_name)
			strbuf_addf(&sb, "--%s", opts->long_name);

		switch (opts->type) {
		case OPTION_INTEGER:
			strbuf_addstr(&sb, " <n>");
			break;
		case OPTION_STRING:
			if (opts->argh)
				strbuf_addf(&sb, " <%s>", opts->argh);
			else
				strbuf_addstr(&sb, " ...");
			break;
		default:
			break;
		}

		pad = sb.len - pos;
		if (pad <= USAGE_OPTS_WIDTH)
			pad = USAGE_OPTS_WIDTH - pad;
		else {
			strbuf_addch(&sb, '\n');
			pad = USAGE_OPTS_WIDTH;
		}
		strbuf_addf(&sb, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
	}
	usage(sb.buf);
}