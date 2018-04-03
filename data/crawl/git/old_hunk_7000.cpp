	else
		ends = "; \t";
	sz = strcspn(ap, ends);
	memcpy(attr, ap, sz);
	attr[sz] = 0;
	return 1;
}

struct content_type {
	char *boundary;
	int boundary_len;
};

static struct content_type content[MAX_BOUNDARIES];

static struct content_type *content_top = content;

static int handle_content_type(char *line)
{
	char boundary[256];

	if (strcasestr(line, "text/") == NULL)
		 message_type = TYPE_OTHER;
	if (slurp_attr(line, "boundary=", boundary + 2)) {
		memcpy(boundary, "--", 2);
		if (content_top++ >= &content[MAX_BOUNDARIES]) {
			fprintf(stderr, "Too many boundaries to handle\n");
			exit(1);
		}
		content_top->boundary_len = strlen(boundary);
		content_top->boundary = xmalloc(content_top->boundary_len+1);
		strcpy(content_top->boundary, boundary);
	}
	if (slurp_attr(line, "charset=", charset)) {
		int i, c;
		for (i = 0; (c = charset[i]) != 0; i++)
			charset[i] = tolower(c);
	}
	return 0;
}

static int handle_content_transfer_encoding(char *line)
{
	if (strcasestr(line, "base64"))
		transfer_encoding = TE_BASE64;
	else if (strcasestr(line, "quoted-printable"))
		transfer_encoding = TE_QP;
	else
		transfer_encoding = TE_DONTCARE;
	return 0;
}

static int is_multipart_boundary(const char *line)
{
	return (!memcmp(line, content_top->boundary, content_top->boundary_len));
}

static int eatspace(char *line)
{
	int len = strlen(line);
	while (len > 0 && isspace(line[len-1]))
		line[--len] = 0;
	return len;
}

static char *cleanup_subject(char *subject)
{
	for (;;) {
		char *p;
		int len, remove;
		switch (*subject) {
		case 'r': case 'R':
			if (!memcmp("e:", subject+1, 2)) {
				subject += 3;
				continue;
			}
			break;
		case ' ': case '\t': case ':':
			subject++;
			continue;

		case '[':
			p = strchr(subject, ']');
			if (!p) {
				subject++;
				continue;
			}
			len = strlen(p);
			remove = p - subject;
			if (remove <= len *2) {
				subject = p+1;
				continue;
			}
			break;
		}
		eatspace(subject);
		return subject;
	}
}

static void cleanup_space(char *buf)
{
	unsigned char c;
	while ((c = *buf) != 0) {
		buf++;
		if (isspace(c)) {
			buf[-1] = ' ';
			c = *buf;
			while (isspace(c)) {
				int len = strlen(buf);
				memmove(buf, buf+1, len);
				c = *buf;
			}
		}
	}
}

static void decode_header(char *it, unsigned itsize);
static const char *header[MAX_HDR_PARSED] = {
	"From","Subject","Date",
};

static int check_header(char *line, unsigned linesize, char **hdr_data, int overwrite)
{
	int i;

	/* search for the interesting parts */
	for (i = 0; header[i]; i++) {
		int len = strlen(header[i]);
		if ((!hdr_data[i] || overwrite) &&
		    !strncasecmp(line, header[i], len) &&
		    line[len] == ':' && isspace(line[len + 1])) {
			/* Unwrap inline B and Q encoding, and optionally
			 * normalize the meta information to utf8.
			 */
			decode_header(line + len + 2, linesize - len - 2);
			hdr_data[i] = xmalloc(1000 * sizeof(char));
			if (! handle_header(line, hdr_data[i], len + 2)) {
				return 1;
			}
		}
	}

	/* Content stuff */
	if (!strncasecmp(line, "Content-Type", 12) &&
		line[12] == ':' && isspace(line[12 + 1])) {
		decode_header(line + 12 + 2, linesize - 12 - 2);
		if (! handle_content_type(line)) {
			return 1;
		}
	}
	if (!strncasecmp(line, "Content-Transfer-Encoding", 25) &&
		line[25] == ':' && isspace(line[25 + 1])) {
		decode_header(line + 25 + 2, linesize - 25 - 2);
		if (! handle_content_transfer_encoding(line)) {
			return 1;
		}
	}

	/* for inbody stuff */
	if (!memcmp(">From", line, 5) && isspace(line[5]))
		return 1;
	if (!memcmp("[PATCH]", line, 7) && isspace(line[7])) {
		for (i = 0; header[i]; i++) {
			if (!memcmp("Subject: ", header[i], 9)) {
				if (! handle_header(line, hdr_data[i], 0)) {
					return 1;
				}
			}
		}
	}

	/* no match */
	return 0;
}

static int is_rfc2822_header(char *line)
{
	/*
	 * The section that defines the loosest possible
