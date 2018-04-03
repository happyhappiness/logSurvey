		ret = 1;

	return (((ret - range->invert) == 0) ? 0 : 1);
} /* int match_range */

static void usage (const char *name)
{
