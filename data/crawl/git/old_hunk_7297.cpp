	return ((it - 1) * (width - 1) + max_change - 1) / (max_change - 1);
}

static void show_name(const char *prefix, const char *name, int len,
		      const char *reset, const char *set)
{
	printf(" %s%s%-*s%s |", set, prefix, len, name, reset);
}

static void show_graph(char ch, int cnt, const char *set, const char *reset)
{
	if (cnt <= 0)
		return;
	printf("%s", set);
	while (cnt--)
		putchar(ch);
	printf("%s", reset);
}

static void fill_print_name(struct diffstat_file *file)
