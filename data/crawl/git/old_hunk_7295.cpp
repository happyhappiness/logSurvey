	return "";
}

static void emit_line(const char *set, const char *reset, const char *line, int len)
{
	fputs(set, stdout);
	fwrite(line, len, 1, stdout);
	fputs(reset, stdout);
}

static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
