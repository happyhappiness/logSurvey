	return "";
}

static unsigned long sane_truncate_line(struct emit_callback *ecb, char *line, unsigned long len)
{
	const char *cp;
