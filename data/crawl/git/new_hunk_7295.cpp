	return "";
}

static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
{
	fputs(set, file);
	fwrite(line, len, 1, file);
	fputs(reset, file);
}

static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
