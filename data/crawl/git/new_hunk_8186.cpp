	return;
}

static void output_header_lines(FILE *fout, const char *hdr, char *data)
{
	while (1) {
		char *ep = strchr(data, '\n');
		int len;
		if (!ep)
			len = strlen(data);
		else
			len = ep - data;
		fprintf(fout, "%s: %.*s\n", hdr, len, data);
		if (!ep)
			break;
		data = ep + 1;
	}
}

static void handle_info(void)
{
	char *sub;
