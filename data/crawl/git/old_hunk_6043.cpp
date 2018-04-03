	NULL
};

int cmd_mktree(int ac, const char **av, const char *prefix)
{
	struct strbuf sb = STRBUF_INIT;
	struct strbuf p_uq = STRBUF_INIT;
	unsigned char sha1[20];
	int line_termination = '\n';
	const struct option option[] = {
