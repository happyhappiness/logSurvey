	strbuf_release(&buf);
}

static void parse_dates(char **argv, struct timeval *now)
{
	struct strbuf result = STRBUF_INIT;
