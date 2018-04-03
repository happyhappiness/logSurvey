static int do_all;
static int do_not_match;
static int seen;
static char delim = '=';
static char key_delim = ' ';
static char term = '\n';
static enum { T_RAW, T_INT, T_BOOL } type = T_RAW;

static int show_all_config(const char *key_, const char *value_)
{
	if (value_)
		printf("%s%c%s%c", key_, delim, value_, term);
	else
		printf("%s%c", key_, term);
	return 0;
}

