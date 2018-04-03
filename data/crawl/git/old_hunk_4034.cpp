	return merged;
}

static int delete_branches(int argc, const char **argv, int force, int kinds,
			   int quiet)
{
	struct commit *rev, *head_rev = NULL;
	unsigned char sha1[20];
	char *name = NULL;
	const char *fmt;
