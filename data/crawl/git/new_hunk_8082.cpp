		 (int)(email_end - email_start - 1), email_start + 1);
}

static const char *clean_message_id(const char *msg_id)
{
	char ch;
	const char *a, *z, *m;
	char *n;
	size_t len;

	m = msg_id;
	while ((ch = *m) && (isspace(ch) || (ch == '<')))
		m++;
	a = m;
	z = NULL;
	while ((ch = *m)) {
		if (!isspace(ch) && (ch != '>'))
			z = m;
		m++;
	}
	if (!z)
		die("insane in-reply-to: %s", msg_id);
	if (++z == m)
		return a;
	len = z - a;
	n = xmalloc(len + 1);
	memcpy(n, a, len);
	n[len] = 0;
	return n;
}

int cmd_format_patch(int argc, const char **argv, const char *prefix)
{
	struct commit *commit;
