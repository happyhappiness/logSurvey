static void show_line(struct grep_opt *opt, const char *bol, const char *eol,
		      const char *name, unsigned lno, char sign)
{
	if (opt->pathname)
		printf("%s%c", name, sign);
	if (opt->linenum)
		printf("%d%c", lno, sign);
	printf("%.*s\n", (int)(eol-bol), bol);
}

static int fixmatch(const char *pattern, char *line, regmatch_t *match)
{
	char *hit = strstr(line, pattern);
