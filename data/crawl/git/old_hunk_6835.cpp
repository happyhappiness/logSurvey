	return (isalpha(ch) || ch == '_' || ch == '$');
}

static void dump_sline(struct sline *sline, unsigned long cnt, int num_parent,
		       int use_color)
{
