		die("empty commit set passed");
}

static int revert_or_cherry_pick(int argc, const char **argv)
{
	struct rev_info revs;
