
	return strbuf_detach(&buf, outsize);
}

static size_t fill_textconv(const char *cmd,
			    struct diff_filespec *df,
			    char **outbuf)
{
	size_t size;

	if (!cmd) {
		if (!DIFF_FILE_VALID(df)) {
			*outbuf = "";
			return 0;
		}
		if (diff_populate_filespec(df, 0))
			die("unable to read files to diff");
		*outbuf = df->data;
		return df->size;
	}

	*outbuf = run_textconv(cmd, df, &size);
	if (!*outbuf)
		die("unable to read files to diff");
	return size;
}