static int do_all;
static int do_not_match;
static int seen;
static enum { T_RAW, T_INT, T_BOOL } type = T_RAW;

static int show_all_config(const char *key_, const char *value_)
{
	if (value_)
		printf("%s=%s\n", key_, value_);
	else
		printf("%s\n", key_);
	return 0;
}

