static const char *output_directory = NULL;
static int outdir_offset;

static int reopen_stdout(struct commit *commit, struct rev_info *rev)
{
	struct strbuf filename = STRBUF_INIT;
	int suffix_len = strlen(fmt_patch_suffix) + 1;

	if (output_directory) {
		strbuf_addstr(&filename, output_directory);
		if (filename.len >=
		    PATH_MAX - FORMAT_PATCH_NAME_MAX - suffix_len)
			return error("name of output directory is too long");
		if (filename.buf[filename.len - 1] != '/')
			strbuf_addch(&filename, '/');
	}

	get_patch_filename(commit, rev->nr, fmt_patch_suffix, &filename);

	if (!DIFF_OPT_TST(&rev->diffopt, QUIET))
		fprintf(realstdout, "%s\n", filename.buf + outdir_offset);

	if (freopen(filename.buf, "w", stdout) == NULL)
		return error("Cannot open patch file %s", filename.buf);

	strbuf_release(&filename);
	return 0;
}

