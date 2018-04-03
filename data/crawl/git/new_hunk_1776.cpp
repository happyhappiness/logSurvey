		struct strbuf *base,
		const char *pathname, unsigned mode, int stage, void *context)
{
	FILE *file = context;
	fprintf(file, "%s%s\n", pathname, S_ISDIR(mode) ? "/" : "");
	return 0;
}

