	return git_config_bool(var, value);
}

static int color_vfprintf(FILE *fp, const char *color, const char *fmt,
		va_list args, const char *trail)
{
	int r = 0;

	if (*color)
		r += fprintf(fp, "%s", color);
	r += vfprintf(fp, fmt, args);
	if (*color)
		r += fprintf(fp, "%s", COLOR_RESET);
	if (trail)
		r += fprintf(fp, "%s", trail);
	return r;
}



int color_fprintf(FILE *fp, const char *color, const char *fmt, ...)
{
	va_list args;
	int r;
	va_start(args, fmt);
	r = color_vfprintf(fp, color, fmt, args, NULL);
	va_end(args);
	return r;
}

int color_fprintf_ln(FILE *fp, const char *color, const char *fmt, ...)
{
	va_list args;
	int r;
	va_start(args, fmt);
	r = color_vfprintf(fp, color, fmt, args, "\n");
	va_end(args);
	return r;
}
