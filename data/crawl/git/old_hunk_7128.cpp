	return 0;
}

static int handle_patch(char *line)
{
	fputs(line, patchfile);
	patch_lines++;
	return 0;
}

static int handle_filter(char *line, unsigned linesize)
{
	static int filter = 0;

