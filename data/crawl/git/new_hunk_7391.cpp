{
	char *buffer = commit->buffer;
	unsigned char tree_sha1[20], sha1[20];
	struct commit_graft *graft;
	int parents = 0;

	if (verbose)
		fprintf(stderr, "Checking commit %s\n",
