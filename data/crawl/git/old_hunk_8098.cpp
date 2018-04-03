	return (non_ascii(ch) || (ch == '=') || (ch == '?') || (ch == '_'));
}

static int add_rfc2047(char *buf, const char *line, int len,
		       const char *encoding)
{
	char *bp = buf;
	int i, needquote;
	char q_encoding[128];
	const char *q_encoding_fmt = "=?%s?q?";

	for (i = needquote = 0; !needquote && i < len; i++) {
		int ch = line[i];
		if (non_ascii(ch))
			needquote++;
		if ((i + 1 < len) &&
		    (ch == '=' && line[i+1] == '?'))
			needquote++;
	}
	if (!needquote)
		return sprintf(buf, "%.*s", len, line);

	i = snprintf(q_encoding, sizeof(q_encoding), q_encoding_fmt, encoding);
	if (sizeof(q_encoding) < i)
		die("Insanely long encoding name %s", encoding);
	memcpy(bp, q_encoding, i);
	bp += i;
	for (i = 0; i < len; i++) {
		unsigned ch = line[i] & 0xFF;
		/*
		 * We encode ' ' using '=20' even though rfc2047
