	return NULL;
}

static void add_message_to_msg(struct strbuf *msgbuf, const char *message)
{
	const char *p = message;
	while (*p && (*p != '\n' || p[1] != '\n'))
		p++;

	if (!*p)
		strbuf_addstr(msgbuf, sha1_to_hex(commit->object.sha1));

	p += 2;
	strbuf_addstr(msgbuf, p);
}

static void set_author_ident_env(const char *message)
