	return name ? name : branch;
}

int cmd_merge_recursive(int argc, const char **argv, const char *prefix)
{
	const char *bases[21];
	unsigned bases_count = 0;
	int i, failed;
	const char *branch1, *branch2;
	unsigned char h1[20], h2[20];
	int subtree_merge = 0;

	if (argv[0]) {
