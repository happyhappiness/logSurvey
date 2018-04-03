	return 0;
}

static int handle_commit_msg(struct strbuf *line)
{
	static int still_looking = 1;

	if (!cmitmsg)
		return 0;

	if (still_looking) {
		strbuf_ltrim(line);
		if (!line->len)
			return 0;
		if ((still_looking = check_header(line, s_hdr_data, 0)) != 0)
			return 0;
	}

	/* normalize the log message to UTF-8. */
	if (metainfo_charset)
		convert_to_utf8(line, charset.buf);

	if (patchbreak(line)) {
		fclose(cmitmsg);
		cmitmsg = NULL;
		return 1;
	}

	fputs(line->buf, cmitmsg);
	return 0;
}

static void handle_patch(const struct strbuf *line)
{
	fwrite(line->buf, 1, line->len, patchfile);
	patch_lines++;
}

static void handle_filter(struct strbuf *line)
{
	static int filter = 0;

	/* filter tells us which part we left off on */
	switch (filter) {
	case 0:
		if (!handle_commit_msg(line))
			break;
		filter++;
	case 1:
		handle_patch(line);
		break;
	}
}

static void handle_body(void)
{
	int len = 0;
	struct strbuf prev = STRBUF_INIT;

	/* Skip up to the first boundary */
	if (*content_top) {
		if (!find_boundary())
			goto handle_body_out;
	}

	do {
		strbuf_setlen(&line, line.len + len);

		/* process any boundary lines */
		if (*content_top && is_multipart_boundary(&line)) {
			/* flush any leftover */
			if (line.len)
				handle_filter(&line);

			if (!handle_boundary())
				goto handle_body_out;
		}

		/* Unwrap transfer encoding */
		decode_transfer_encoding(&line);

		switch (transfer_encoding) {
		case TE_BASE64:
		case TE_QP:
		{
			struct strbuf **lines, **it, *sb;

			/* Prepend any previous partial lines */
			strbuf_insert(&line, 0, prev.buf, prev.len);
			strbuf_reset(&prev);

			/* binary data most likely doesn't have newlines */
			if (message_type != TYPE_TEXT) {
				handle_filter(&line);
				break;
			}
			/*
			 * This is a decoded line that may contain
			 * multiple new lines.  Pass only one chunk
			 * at a time to handle_filter()
			 */
			lines = strbuf_split(&line, '\n');
			for (it = lines; (sb = *it); it++) {
				if (*(it + 1) == NULL) /* The last line */
					if (sb->buf[sb->len - 1] != '\n') {
						/* Partial line, save it for later. */
						strbuf_addbuf(&prev, sb);
						break;
					}
				handle_filter(sb);
			}
			/*
			 * The partial chunk is saved in "prev" and will be
			 * appended by the next iteration of read_line_with_nul().
			 */
			strbuf_list_free(lines);
			break;
		}
		default:
			handle_filter(&line);
		}

		strbuf_reset(&line);
		if (strbuf_avail(&line) < 100)
			strbuf_grow(&line, 100);
	} while ((len = read_line_with_nul(line.buf, strbuf_avail(&line), fin)));

handle_body_out:
	strbuf_release(&prev);
}

static void output_header_lines(FILE *fout, const char *hdr, const struct strbuf *data)
{
	const char *sp = data->buf;
	while (1) {
		char *ep = strchr(sp, '\n');
		int len;
		if (!ep)
			len = strlen(sp);
		else
			len = ep - sp;
		fprintf(fout, "%s: %.*s\n", hdr, len, sp);
		if (!ep)
			break;
		sp = ep + 1;
	}
}

static void handle_info(void)
{
	struct strbuf *hdr;
	int i;

	for (i = 0; header[i]; i++) {
		/* only print inbody headers if we output a patch file */
		if (patch_lines && s_hdr_data[i])
			hdr = s_hdr_data[i];
