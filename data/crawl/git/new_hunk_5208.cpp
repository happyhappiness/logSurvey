	fprintf(stderr, "Finished one %s.\n", me);
}

static int do_pick_commit(void)
{
	unsigned char head[20];
	struct commit *base, *next, *parent;
