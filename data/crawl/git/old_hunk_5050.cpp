			sha1_to_hex(commit->object.sha1));
}

static char *help_msg(void)
{
	struct strbuf helpbuf = STRBUF_INIT;