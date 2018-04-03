#define OPT_SHORT 1
#define OPT_UNSET 2

static int opterror(const struct option *opt, const char *reason, int flags)
{
	if (flags & OPT_SHORT)
