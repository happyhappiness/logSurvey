	printf("%.*s\n", rest, bol);
}

static void show_pre_context(struct grep_opt *opt, const char *name, char *buf,
			     char *bol, unsigned lno)
{
	unsigned cur = lno, from = 1;

	if (opt->pre_context < lno)
		from = lno - opt->pre_context;
