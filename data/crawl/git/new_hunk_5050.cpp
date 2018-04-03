			sha1_to_hex(commit->object.sha1));
}

static void advise(const char *advice, ...)
{
	va_list params;

	va_start(params, advice);
	vreportf("hint: ", advice, params);
	va_end(params);
}

static char *help_msg(void)
{
	struct strbuf helpbuf = STRBUF_INIT;