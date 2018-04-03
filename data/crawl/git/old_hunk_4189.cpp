	file->print_name = pname;
}

static void show_stats(struct diffstat_t *data, struct diff_options *options)
{
	int i, len, add, del, adds = 0, dels = 0;
