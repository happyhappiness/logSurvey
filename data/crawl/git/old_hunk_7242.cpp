	die("unrecognized help format '%s'", format);
}

static int check_emacsclient_version(void)
{
	struct strbuf buffer = STRBUF_INIT;
