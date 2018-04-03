}

static void show_name(FILE *file,
		      const char *prefix, const char *name, int len,
		      const char *reset, const char *set)
{
	fprintf(file, " %s%s%-*s%s |", set, prefix, len, name, reset);
}

static void show_graph(FILE *file, char ch, int cnt, const char *set, const char *reset)
