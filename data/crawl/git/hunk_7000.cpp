 	else
 		ends = "; \t";
 	sz = strcspn(ap, ends);
-	memcpy(attr, ap, sz);
-	attr[sz] = 0;
+	strbuf_add(attr, ap, sz);
 	return 1;
 }
 
-struct content_type {
-	char *boundary;
-	int boundary_len;
-};
-
-static struct content_type content[MAX_BOUNDARIES];
+static struct strbuf *content[MAX_BOUNDARIES];
 
-static struct content_type *content_top = content;
+static struct strbuf **content_top = content;
 
-static int handle_content_type(char *line)
+static void handle_content_type(struct strbuf *line)
 {
-	char boundary[256];
+	struct strbuf *boundary = xmalloc(sizeof(struct strbuf));
+	strbuf_init(boundary, line->len);
 
-	if (strcasestr(line, "text/") == NULL)
+	if (!strcasestr(line->buf, "text/"))
 		 message_type = TYPE_OTHER;
-	if (slurp_attr(line, "boundary=", boundary + 2)) {
-		memcpy(boundary, "--", 2);
+	if (slurp_attr(line->buf, "boundary=", boundary)) {
+		strbuf_insert(boundary, 0, "--", 2);
 		if (content_top++ >= &content[MAX_BOUNDARIES]) {
 			fprintf(stderr, "Too many boundaries to handle\n");
 			exit(1);
 		}
-		content_top->boundary_len = strlen(boundary);
-		content_top->boundary = xmalloc(content_top->boundary_len+1);
-		strcpy(content_top->boundary, boundary);
+		*content_top = boundary;
+		boundary = NULL;
 	}
-	if (slurp_attr(line, "charset=", charset)) {
-		int i, c;
-		for (i = 0; (c = charset[i]) != 0; i++)
-			charset[i] = tolower(c);
+	if (slurp_attr(line->buf, "charset=", &charset))
+		strbuf_tolower(&charset);
+
+	if (boundary) {
+		strbuf_release(boundary);
+		free(boundary);
 	}
-	return 0;
 }
 
-static int handle_content_transfer_encoding(char *line)
+static void handle_content_transfer_encoding(const struct strbuf *line)
 {
-	if (strcasestr(line, "base64"))
+	if (strcasestr(line->buf, "base64"))
 		transfer_encoding = TE_BASE64;
-	else if (strcasestr(line, "quoted-printable"))
+	else if (strcasestr(line->buf, "quoted-printable"))
 		transfer_encoding = TE_QP;
 	else
 		transfer_encoding = TE_DONTCARE;
-	return 0;
 }
 
-static int is_multipart_boundary(const char *line)
+static int is_multipart_boundary(const struct strbuf *line)
 {
-	return (!memcmp(line, content_top->boundary, content_top->boundary_len));
+	return !strbuf_cmp(line, *content_top);
 }
 
-static int eatspace(char *line)
+static void cleanup_subject(struct strbuf *subject)
 {
-	int len = strlen(line);
-	while (len > 0 && isspace(line[len-1]))
-		line[--len] = 0;
-	return len;
-}
-
-static char *cleanup_subject(char *subject)
-{
-	for (;;) {
-		char *p;
-		int len, remove;
-		switch (*subject) {
+	char *pos;
+	size_t remove;
+	while (subject->len) {
+		switch (*subject->buf) {
 		case 'r': case 'R':
-			if (!memcmp("e:", subject+1, 2)) {
-				subject += 3;
+			if (subject->len <= 3)
+				break;
+			if (!memcmp(subject->buf + 1, "e:", 2)) {
+				strbuf_remove(subject, 0, 3);
 				continue;
 			}
 			break;
 		case ' ': case '\t': case ':':
-			subject++;
+			strbuf_remove(subject, 0, 1);
 			continue;
-
 		case '[':
-			p = strchr(subject, ']');
-			if (!p) {
-				subject++;
-				continue;
-			}
-			len = strlen(p);
-			remove = p - subject;
-			if (remove <= len *2) {
-				subject = p+1;
-				continue;
-			}
+			if ((pos = strchr(subject->buf, ']'))) {
+				remove = pos - subject->buf + 1;
+				/* Don't remove too much. */
+				if (remove <= (subject->len - remove + 1) * 2) {
+					strbuf_remove(subject, 0, remove);
+					continue;
+				}
+			} else
+				strbuf_remove(subject, 0, 1);
 			break;
 		}
-		eatspace(subject);
-		return subject;
+		strbuf_trim(subject);
+		return;
 	}
 }
 
-static void cleanup_space(char *buf)
+static void cleanup_space(struct strbuf *sb)
 {
-	unsigned char c;
-	while ((c = *buf) != 0) {
-		buf++;
-		if (isspace(c)) {
-			buf[-1] = ' ';
-			c = *buf;
-			while (isspace(c)) {
-				int len = strlen(buf);
-				memmove(buf, buf+1, len);
-				c = *buf;
-			}
+	size_t pos, cnt;
+	for (pos = 0; pos < sb->len; pos++) {
+		if (isspace(sb->buf[pos])) {
+			sb->buf[pos] = ' ';
+			for (cnt = 0; isspace(sb->buf[pos + cnt + 1]); cnt++);
+			strbuf_remove(sb, pos + 1, cnt);
 		}
 	}
 }
 
-static void decode_header(char *it, unsigned itsize);
+static void decode_header(struct strbuf *line);
 static const char *header[MAX_HDR_PARSED] = {
 	"From","Subject","Date",
 };
 
-static int check_header(char *line, unsigned linesize, char **hdr_data, int overwrite)
+static inline int cmp_header(const struct strbuf *line, const char *hdr)
 {
-	int i;
+	int len = strlen(hdr);
+	return !strncasecmp(line->buf, hdr, len) && line->len > len &&
+			line->buf[len] == ':' && isspace(line->buf[len + 1]);
+}
 
+static int check_header(const struct strbuf *line,
+				struct strbuf *hdr_data[], int overwrite)
+{
+	int i, ret = 0, len;
+	struct strbuf sb = STRBUF_INIT;
 	/* search for the interesting parts */
 	for (i = 0; header[i]; i++) {
 		int len = strlen(header[i]);
-		if ((!hdr_data[i] || overwrite) &&
-		    !strncasecmp(line, header[i], len) &&
-		    line[len] == ':' && isspace(line[len + 1])) {
+		if ((!hdr_data[i] || overwrite) && cmp_header(line, header[i])) {
 			/* Unwrap inline B and Q encoding, and optionally
 			 * normalize the meta information to utf8.
 			 */
-			decode_header(line + len + 2, linesize - len - 2);
-			hdr_data[i] = xmalloc(1000 * sizeof(char));
-			if (! handle_header(line, hdr_data[i], len + 2)) {
-				return 1;
-			}
+			strbuf_add(&sb, line->buf + len + 2, line->len - len - 2);
+			decode_header(&sb);
+			handle_header(&hdr_data[i], &sb);
+			ret = 1;
+			goto check_header_out;
 		}
 	}
 
 	/* Content stuff */
-	if (!strncasecmp(line, "Content-Type", 12) &&
-		line[12] == ':' && isspace(line[12 + 1])) {
-		decode_header(line + 12 + 2, linesize - 12 - 2);
-		if (! handle_content_type(line)) {
-			return 1;
-		}
-	}
-	if (!strncasecmp(line, "Content-Transfer-Encoding", 25) &&
-		line[25] == ':' && isspace(line[25 + 1])) {
-		decode_header(line + 25 + 2, linesize - 25 - 2);
-		if (! handle_content_transfer_encoding(line)) {
-			return 1;
-		}
+	if (cmp_header(line, "Content-Type")) {
+		len = strlen("Content-Type: ");
+		strbuf_add(&sb, line->buf + len, line->len - len);
+		decode_header(&sb);
+		strbuf_insert(&sb, 0, "Content-Type: ", len);
+		handle_content_type(&sb);
+		ret = 1;
+		goto check_header_out;
+	}
+	if (cmp_header(line, "Content-Transfer-Encoding")) {
+		len = strlen("Content-Transfer-Encoding: ");
+		strbuf_add(&sb, line->buf + len, line->len - len);
+		decode_header(&sb);
+		handle_content_transfer_encoding(&sb);
+		ret = 1;
+		goto check_header_out;
 	}
 
 	/* for inbody stuff */
-	if (!memcmp(">From", line, 5) && isspace(line[5]))
-		return 1;
-	if (!memcmp("[PATCH]", line, 7) && isspace(line[7])) {
+	if (!prefixcmp(line->buf, ">From") && isspace(line->buf[5])) {
+		ret = 1; /* Should this return 0? */
+		goto check_header_out;
+	}
+	if (!prefixcmp(line->buf, "[PATCH]") && isspace(line->buf[7])) {
 		for (i = 0; header[i]; i++) {
-			if (!memcmp("Subject: ", header[i], 9)) {
-				if (! handle_header(line, hdr_data[i], 0)) {
-					return 1;
-				}
+			if (!memcmp("Subject", header[i], 7)) {
+				handle_header(&hdr_data[i], line);
+				ret = 1;
+				goto check_header_out;
 			}
 		}
 	}
 
-	/* no match */
-	return 0;
+check_header_out:
+	strbuf_release(&sb);
+	return ret;
 }
 
-static int is_rfc2822_header(char *line)
+static int is_rfc2822_header(const struct strbuf *line)
 {
 	/*
 	 * The section that defines the loosest possible
