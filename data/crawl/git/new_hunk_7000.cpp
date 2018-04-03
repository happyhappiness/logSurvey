	else
		ends = "; \t";
	sz = strcspn(ap, ends);
	strbuf_add(attr, ap, sz);
	return 1;
}

static struct strbuf *content[MAX_BOUNDARIES];

static struct strbuf **content_top = content;

static void handle_content_type(struct strbuf *line)
{
	struct strbuf *boundary = xmalloc(sizeof(struct strbuf));
	strbuf_init(boundary, line->len);

	if (!strcasestr(line->buf, "text/"))
		 message_type = TYPE_OTHER;
	if (slurp_attr(line->buf, "boundary=", boundary)) {
		strbuf_insert(boundary, 0, "--", 2);
		if (content_top++ >= &content[MAX_BOUNDARIES]) {
			fprintf(stderr, "Too many boundaries to handle\n");
			exit(1);
		}
		*content_top = boundary;
		boundary = NULL;
	}
	if (slurp_attr(line->buf, "charset=", &charset))
		strbuf_tolower(&charset);

	if (boundary) {
		strbuf_release(boundary);
		free(boundary);
	}
}

static void handle_content_transfer_encoding(const struct strbuf *line)
{
	if (strcasestr(line->buf, "base64"))
		transfer_encoding = TE_BASE64;
	else if (strcasestr(line->buf, "quoted-printable"))
		transfer_encoding = TE_QP;
	else
		transfer_encoding = TE_DONTCARE;
}

static int is_multipart_boundary(const struct strbuf *line)
{
	return !strbuf_cmp(line, *content_top);
}

static void cleanup_subject(struct strbuf *subject)
{
	char *pos;
	size_t remove;
	while (subject->len) {
		switch (*subject->buf) {
		case 'r': case 'R':
			if (subject->len <= 3)
				break;
			if (!memcmp(subject->buf + 1, "e:", 2)) {
				strbuf_remove(subject, 0, 3);
				continue;
			}
			break;
		case ' ': case '\t': case ':':
			strbuf_remove(subject, 0, 1);
			continue;
		case '[':
			if ((pos = strchr(subject->buf, ']'))) {
				remove = pos - subject->buf + 1;
				/* Don't remove too much. */
				if (remove <= (subject->len - remove + 1) * 2) {
					strbuf_remove(subject, 0, remove);
					continue;
				}
			} else
				strbuf_remove(subject, 0, 1);
			break;
		}
		strbuf_trim(subject);
		return;
	}
}

static void cleanup_space(struct strbuf *sb)
{
	size_t pos, cnt;
	for (pos = 0; pos < sb->len; pos++) {
		if (isspace(sb->buf[pos])) {
			sb->buf[pos] = ' ';
			for (cnt = 0; isspace(sb->buf[pos + cnt + 1]); cnt++);
			strbuf_remove(sb, pos + 1, cnt);
		}
	}
}

static void decode_header(struct strbuf *line);
static const char *header[MAX_HDR_PARSED] = {
	"From","Subject","Date",
};

static inline int cmp_header(const struct strbuf *line, const char *hdr)
{
	int len = strlen(hdr);
	return !strncasecmp(line->buf, hdr, len) && line->len > len &&
			line->buf[len] == ':' && isspace(line->buf[len + 1]);
}

static int check_header(const struct strbuf *line,
				struct strbuf *hdr_data[], int overwrite)
{
	int i, ret = 0, len;
	struct strbuf sb = STRBUF_INIT;
	/* search for the interesting parts */
	for (i = 0; header[i]; i++) {
		int len = strlen(header[i]);
		if ((!hdr_data[i] || overwrite) && cmp_header(line, header[i])) {
			/* Unwrap inline B and Q encoding, and optionally
			 * normalize the meta information to utf8.
			 */
			strbuf_add(&sb, line->buf + len + 2, line->len - len - 2);
			decode_header(&sb);
			handle_header(&hdr_data[i], &sb);
			ret = 1;
			goto check_header_out;
		}
	}

	/* Content stuff */
	if (cmp_header(line, "Content-Type")) {
		len = strlen("Content-Type: ");
		strbuf_add(&sb, line->buf + len, line->len - len);
		decode_header(&sb);
		strbuf_insert(&sb, 0, "Content-Type: ", len);
		handle_content_type(&sb);
		ret = 1;
		goto check_header_out;
	}
	if (cmp_header(line, "Content-Transfer-Encoding")) {
		len = strlen("Content-Transfer-Encoding: ");
		strbuf_add(&sb, line->buf + len, line->len - len);
		decode_header(&sb);
		handle_content_transfer_encoding(&sb);
		ret = 1;
		goto check_header_out;
	}

	/* for inbody stuff */
	if (!prefixcmp(line->buf, ">From") && isspace(line->buf[5])) {
		ret = 1; /* Should this return 0? */
		goto check_header_out;
	}
	if (!prefixcmp(line->buf, "[PATCH]") && isspace(line->buf[7])) {
		for (i = 0; header[i]; i++) {
			if (!memcmp("Subject", header[i], 7)) {
				handle_header(&hdr_data[i], line);
				ret = 1;
				goto check_header_out;
			}
		}
	}

check_header_out:
	strbuf_release(&sb);
	return ret;
}

static int is_rfc2822_header(const struct strbuf *line)
{
	/*
	 * The section that defines the loosest possible
