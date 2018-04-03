{
	struct strbuf str = STRBUF_INIT;
	const char *filename = git_path_bisect_names();
	FILE *fp = xfopen(filename, "r");

	while (strbuf_getline_lf(&str, fp) != EOF) {
		strbuf_trim(&str);
