	return git_default_config(var, value, cb);
}

static int color_vfprintf(FILE *fp, const char *color, const char *fmt,
		va_list args, const char *trail)
{
