	return 0;
}

static int handle_patch(char *line, int len)
{
	fwrite(line, 1, len, patchfile);
	patch_lines++;
	return 0;
}

static int handle_filter(char *line, unsigned linesize, int linelen)
{
	static int filter = 0;

