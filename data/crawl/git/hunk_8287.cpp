 	return strlen(*buf_p);
 }
 
+static void pp_header(enum cmit_fmt fmt,
+		      int abbrev,
+		      enum date_mode dmode,
+		      const char *encoding,
+		      const struct commit *commit,
+		      const char **msg_p,
+		      unsigned long *len_p,
+		      unsigned long *ofs_p,
+		      char **buf_p,
+		      unsigned long *space_p)
+{
+	int parents_shown = 0;
+
+	for (;;) {
+		const char *line = *msg_p;
+		char *dst;
+		int linelen = get_one_line(*msg_p, *len_p);
+		unsigned long len;
+
+		if (!linelen)
+			return;
+		*msg_p += linelen;
+		*len_p -= linelen;
+
+		if (linelen == 1)
+			/* End of header */
+			return;
+
+		ALLOC_GROW(*buf_p, linelen + *ofs_p + 20, *space_p);
+		dst = *buf_p + *ofs_p;
+
+		if (fmt == CMIT_FMT_RAW) {
+			memcpy(dst, line, linelen);
+			*ofs_p += linelen;
+			continue;
+		}
+
+		if (!memcmp(line, "parent ", 7)) {
+			if (linelen != 48)
+				die("bad parent line in commit");
+			continue;
+		}
+
+		if (!parents_shown) {
+			struct commit_list *parent;
+			int num;
+			for (parent = commit->parents, num = 0;
+			     parent;
+			     parent = parent->next, num++)
+				;
+			/* with enough slop */
+			num = *ofs_p + num * 50 + 20;
+			ALLOC_GROW(*buf_p, num, *space_p);
+			dst = *buf_p + *ofs_p;
+			*ofs_p += add_merge_info(fmt, dst, commit, abbrev);
+			parents_shown = 1;
+		}
+
+		/*
+		 * MEDIUM == DEFAULT shows only author with dates.
+		 * FULL shows both authors but not dates.
+		 * FULLER shows both authors and dates.
+		 */
+		if (!memcmp(line, "author ", 7)) {
+			len = linelen;
+			if (fmt == CMIT_FMT_EMAIL)
+				len = bound_rfc2047(linelen, encoding);
+			ALLOC_GROW(*buf_p, *ofs_p + len, *space_p);
+			dst = *buf_p + *ofs_p;
+			*ofs_p += add_user_info("Author", fmt, dst,
+						line + 7, dmode, encoding);
+		}
+
+		if (!memcmp(line, "committer ", 10) &&
+		    (fmt == CMIT_FMT_FULL || fmt == CMIT_FMT_FULLER)) {
+			len = linelen;
+			if (fmt == CMIT_FMT_EMAIL)
+				len = bound_rfc2047(linelen, encoding);
+			ALLOC_GROW(*buf_p, *ofs_p + len, *space_p);
+			dst = *buf_p + *ofs_p;
+			*ofs_p += add_user_info("Commit", fmt, dst,
+						line + 10, dmode, encoding);
+		}
+	}
+}
+
+static void pp_title_line(enum cmit_fmt fmt,
+			  const char **msg_p,
+			  unsigned long *len_p,
+			  unsigned long *ofs_p,
+			  char **buf_p,
+			  unsigned long *space_p,
+			  int indent,
+			  const char *subject,
+			  const char *after_subject,
+			  const char *encoding,
+			  int plain_non_ascii)
+{
+	char *title;
+	unsigned long title_alloc, title_len;
+	unsigned long len;
+
+	title_len = 0;
+	title_alloc = 80;
+	title = xmalloc(title_alloc);
+	for (;;) {
+		const char *line = *msg_p;
+		int linelen = get_one_line(line, *len_p);
+		*msg_p += linelen;
+		*len_p -= linelen;
+
+		if (!linelen || is_empty_line(line, &linelen))
+			break;
+
+		if (title_alloc <= title_len + linelen + 2) {
+			title_alloc = title_len + linelen + 80;
+			title = xrealloc(title, title_alloc);
+		}
+		len = 0;
+		if (title_len) {
+			if (fmt == CMIT_FMT_EMAIL) {
+				len++;
+				title[title_len++] = '\n';
+			}
+			len++;
+			title[title_len++] = ' ';
+		}
+		memcpy(title + title_len, line, linelen);
+		title_len += linelen;
+	}
+
+	/* Enough slop for the MIME header and rfc2047 */
+	len = bound_rfc2047(title_len, encoding)+ 1000;
+	if (subject)
+		len += strlen(subject);
+	if (after_subject)
+		len += strlen(after_subject);
+	if (encoding)
+		len += strlen(encoding);
+	ALLOC_GROW(*buf_p, title_len + *ofs_p + len, *space_p);
+
+	if (subject) {
+		len = strlen(subject);
+		memcpy(*buf_p + *ofs_p, subject, len);
+		*ofs_p += len;
+		*ofs_p += add_rfc2047(*buf_p + *ofs_p,
+				      title, title_len, encoding);
+	} else {
+		memcpy(*buf_p + *ofs_p, title, title_len);
+		*ofs_p += title_len;
+	}
+	(*buf_p)[(*ofs_p)++] = '\n';
+	if (plain_non_ascii) {
+		const char *header_fmt =
+			"MIME-Version: 1.0\n"
+			"Content-Type: text/plain; charset=%s\n"
+			"Content-Transfer-Encoding: 8bit\n";
+		*ofs_p += snprintf(*buf_p + *ofs_p,
+				   *space_p - *ofs_p,
+				   header_fmt, encoding);
+	}
+	if (after_subject) {
+		len = strlen(after_subject);
+		memcpy(*buf_p + *ofs_p, after_subject, len);
+		*ofs_p += len;
+	}
+	free(title);
+	if (fmt == CMIT_FMT_EMAIL) {
+		ALLOC_GROW(*buf_p, *ofs_p + 20, *space_p);
+		(*buf_p)[(*ofs_p)++] = '\n';
+	}
+}
+
+static void pp_remainder(enum cmit_fmt fmt,
+			 const char **msg_p,
+			 unsigned long *len_p,
+			 unsigned long *ofs_p,
+			 char **buf_p,
+			 unsigned long *space_p,
+			 int indent)
+{
+	int first = 1;
+	for (;;) {
+		const char *line = *msg_p;
+		int linelen = get_one_line(line, *len_p);
+		*msg_p += linelen;
+		*len_p -= linelen;
+
+		if (!linelen)
+			break;
+
+		if (is_empty_line(line, &linelen)) {
+			if (first)
+				continue;
+			if (fmt == CMIT_FMT_SHORT)
+				break;
+		}
+		first = 0;
+
+		ALLOC_GROW(*buf_p, *ofs_p + linelen + indent + 20, *space_p);
+		if (indent) {
+			memset(*buf_p + *ofs_p, ' ', indent);
+			*ofs_p += indent;
+		}
+		memcpy(*buf_p + *ofs_p, line, linelen);
+		*ofs_p += linelen;
+		(*buf_p)[(*ofs_p)++] = '\n';
+	}
+}
+
 unsigned long pretty_print_commit(enum cmit_fmt fmt,
 				  const struct commit *commit,
 				  unsigned long len,
