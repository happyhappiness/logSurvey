	return ((it - 1) * (width - 1) + max_change - 1) / (max_change - 1);
}

static void show_name(FILE *file,
		      const char *prefix, const char *name, int len,
		      const char *reset, const char *set)
{
	fprintf(file, " %s%s%-*s%s |", set, prefix, len, name, reset);
}

static void show_graph(FILE *file, char ch, int cnt, const char *set, const char *reset)
{
	if (cnt <= 0)
		return;
	fprintf(file, "%s", set);
	while (cnt--)
		putc(ch, file);
	fprintf(file, "%s", reset);
}

static void fill_print_name(struct diffstat_file *file)
