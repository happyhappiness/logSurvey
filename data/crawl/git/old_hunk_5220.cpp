	const char *meta = diff_get_color(ecbdata->color_diff, DIFF_METAINFO);
	const char *plain = diff_get_color(ecbdata->color_diff, DIFF_PLAIN);
	const char *reset = diff_get_color(ecbdata->color_diff, DIFF_RESET);

	if (ecbdata->header) {
		fprintf(ecbdata->opt->file, "%s", ecbdata->header->buf);
