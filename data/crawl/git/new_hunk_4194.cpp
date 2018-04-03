	return data;
}

static int grep_sha1(struct grep_opt *opt, const unsigned char *sha1,
		     const char *filename, int tree_name_len)
{
	struct strbuf pathbuf = STRBUF_INIT;

	if (opt->relative && opt->prefix_length) {
		quote_path_relative(filename + tree_name_len, -1, &pathbuf,
