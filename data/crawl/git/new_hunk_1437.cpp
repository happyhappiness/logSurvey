	const char *line_prefix = diff_line_prefix(o);

	if (ecbdata->header) {
		fprintf(o->file, "%s", ecbdata->header->buf);
		strbuf_reset(ecbdata->header);
		ecbdata->header = NULL;
	}
