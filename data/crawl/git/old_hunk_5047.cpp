	va_end(params);
}

static char *help_msg(void)
{
	struct strbuf helpbuf = STRBUF_INIT;
	char *msg = getenv("GIT_CHERRY_PICK_HELP");

	if (msg)
		return msg;

	strbuf_addstr(&helpbuf, "  After resolving the conflicts,\n"
		"mark the corrected paths with 'git add <paths>' or 'git rm <paths>'\n"
		"and commit the result");

	if (action == CHERRY_PICK) {
		strbuf_addf(&helpbuf, " with: \n"
			"\n"
			"        git commit -c %s\n",
			    sha1_to_hex(commit->object.sha1));
	}
	else
		strbuf_addch(&helpbuf, '.');
	return strbuf_detach(&helpbuf, NULL);
}

static void write_message(struct strbuf *msgbuf, const char *filename)
