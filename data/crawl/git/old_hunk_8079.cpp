	else die("maximum number of args exceeded"); \
	} while (0)

static int external_grep(struct grep_opt *opt, const char **paths, int cached)
{
	int i, nr, argc, hit, len, status;
