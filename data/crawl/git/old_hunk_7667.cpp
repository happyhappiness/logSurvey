	printf("%s", reset);
}

static void show_stats(struct diffstat_t* data, struct diff_options *options)
{
	int i, len, add, del, total, adds = 0, dels = 0;
