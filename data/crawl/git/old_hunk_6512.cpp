	char tmp_path[PATH_MAX];
} diff_temp[2];

static int count_lines(const char *data, int size)
{
	int count, ch, completely_empty = 1, nl_just_seen = 0;
