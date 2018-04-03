	return (e < 3 * x) ? n : n - 1;
}

int cmd_rev_list(int argc, const char **argv, const char *prefix)
{
	struct commit_list *list;
