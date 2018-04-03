	fprintf(stderr, "Finished one %s.\n", me);
}

static int revert_or_cherry_pick(int argc, const char **argv)
{
	unsigned char head[20];
	struct commit *base, *next, *parent;
