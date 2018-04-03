	printf("\n");
}

static int show_or_prune(int argc, const char **argv, int prune)
{
	int no_query = 0, result = 0;
	struct option options[] = {
