	return 0;
}


static int handle_commit_msg(char *line, unsigned linesize)
{
	static int still_looking = 1;
	char *endline = line + linesize;

	if (!cmitmsg)
		return 0;

	if (still_looking) {
		char *cp = line;
		if (isspace(*line)) {
			for (cp = line + 1; *cp; cp++) {
				if (!isspace(*cp))
					break;
			}
			if (!*cp)
				return 0;
		}
		if ((still_looking = check_header(cp, endline - cp, s_hdr_data, 0)) != 0)
			return 0;
	}

	/* normalize the log message to UTF-8. */
	if (metainfo_charset)
		convert_to_utf8(line, endline - line, charset);

	if (patchbreak(line)) {
		fclose(cmitmsg);
		cmitmsg = NULL;
		return 1;
	}

	fputs(line, cmitmsg);
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

	/* filter tells us which part we left off on
	 * a non-zero return indicates we hit a filter point
	 */
	switch (filter) {
	case 0:
		if (!handle_commit_msg(line, linesize))
			break;
		filter++;
	case 1:
		if (!handle_patch(line, linelen))
			break;
		filter++;
	default:
		return 1;
	}

	return 0;
}

static void handle_body(void)
{
	int rc = 0;
	static char newline[2000];
	static char *np = newline;
	int len = strlen(line);

	/* Skip up to the first boundary */
	if (content_top->boundary) {
		if (!find_boundary())
			return;
	}

	do {
		/* process any boundary lines */
		if (content_top->boundary && is_multipart_boundary(line)) {
			/* flush any leftover */
			if (np != newline)
				handle_filter(newline, sizeof(newline),
					      np - newline);
			if (!handle_boundary())
				return;
			len = strlen(line);
		}

		/* Unwrap transfer encoding */
		len = decode_transfer_encoding(line, sizeof(line), len);
		if (len < 0) {
			error("Malformed input line");
			return;
		}

		switch (transfer_encoding) {
		case TE_BASE64:
		case TE_QP:
		{
			char *op = line;

			/* binary data most likely doesn't have newlines */
			if (message_type != TYPE_TEXT) {
				rc = handle_filter(line, sizeof(line), len);
				break;
			}

			/*
			 * This is a decoded line that may contain
			 * multiple new lines.  Pass only one chunk
			 * at a time to handle_filter()
			 */
			do {
				while (op < line + len && *op != '\n')
					*np++ = *op++;
				*np = *op;
				if (*np != 0) {
					/* should be sitting on a new line */
					*(++np) = 0;
					op++;
					rc = handle_filter(newline, sizeof(newline), np - newline);
					np = newline;
				}
			} while (op < line + len);
			/*
			 * The partial chunk is saved in newline and will be
			 * appended by the next iteration of read_line_with_nul().
			 */
			break;
		}
		default:
			rc = handle_filter(line, sizeof(line), len);
		}
		if (rc)
			/* nothing left to filter */
			break;
	} while ((len = read_line_with_nul(line, sizeof(line), fin)));

	return;
}

static void output_header_lines(FILE *fout, const char *hdr, char *data)
{
	while (1) {
		char *ep = strchr(data, '\n');
		int len;
		if (!ep)
			len = strlen(data);
		else
			len = ep - data;
		fprintf(fout, "%s: %.*s\n", hdr, len, data);
		if (!ep)
			break;
		data = ep + 1;
	}
}

static void handle_info(void)
{
	char *sub;
	char *hdr;
	int i;

	for (i = 0; header[i]; i++) {

		/* only print inbody headers if we output a patch file */
		if (patch_lines && s_hdr_data[i])
			hdr = s_hdr_data[i];
