	fprintf(fout, "\n");
}

static int mailinfo(FILE *in, FILE *out, const char *msg, const char *patch)
{
	int peek;
	struct strbuf line = STRBUF_INIT;
