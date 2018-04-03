{
	struct strbuf str = STRBUF_INIT;
	const char *filename = git_path_bisect_names();
	FILE *fp = fopen(filename, "r");

	if (!fp)
		die_errno(_("Could not open file '%s'"), filename);

	while (strbuf_getline_lf(&str, fp) != EOF) {
		strbuf_trim(&str);
