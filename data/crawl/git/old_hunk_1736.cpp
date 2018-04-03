	return 1;
}

static void compile_regexp(struct grep_pat *p, struct grep_opt *opt)
{
	int icase, ascii_only;
