	return 0;
}

const char *make_relative_path(const char *abs, const char *base)
{
	static char buf[PATH_MAX + 1];