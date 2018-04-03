
void diff_no_index(struct rev_info *revs,
		   int argc, const char **argv,
		   const char *prefix)
{
	int i, prefixlen;
	unsigned deprecated_show_diff_q_option_used = 0;
	const char *paths[2];

	diff_setup(&revs->diffopt);
	for (i = 1; i < argc - 2; ) {
		int j;
