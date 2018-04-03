	usage_with_options(builtin_config_usage, builtin_config_options);
}

static void show_config_origin(struct strbuf *buf)
{
	const char term = end_null ? '\0' : '\t';

	strbuf_addstr(buf, current_config_origin_type());
	strbuf_addch(buf, ':');
	if (end_null)
		strbuf_addstr(buf, current_config_name());
	else
		quote_c_style(current_config_name(), buf, NULL, 0);
	strbuf_addch(buf, term);
}

static int show_all_config(const char *key_, const char *value_, void *cb)
{
	if (show_origin) {
		struct strbuf buf = STRBUF_INIT;
		show_config_origin(&buf);
		/* Use fwrite as "buf" can contain \0's if "end_null" is set. */
		fwrite(buf.buf, 1, buf.len, stdout);
		strbuf_release(&buf);
	}
	if (!omit_values && value_)
		printf("%s%c%s%c", key_, delim, value_, term);
	else
