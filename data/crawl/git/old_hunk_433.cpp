	sb->copy_score = BLAME_DEFAULT_COPY_SCORE;
}

int cmd_blame(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
