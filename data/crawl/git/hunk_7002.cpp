 	return 0;
 }
 
-
-static int handle_commit_msg(char *line, unsigned linesize)
+static int handle_commit_msg(struct strbuf *line)
 {
 	static int still_looking = 1;
-	char *endline = line + linesize;
 
 	if (!cmitmsg)
 		return 0;
 
 	if (still_looking) {
-		char *cp = line;
-		if (isspace(*line)) {
-			for (cp = line + 1; *cp; cp++) {
-				if (!isspace(*cp))
-					break;
-			}
-			if (!*cp)
-				return 0;
-		}
-		if ((still_looking = check_header(cp, endline - cp, s_hdr_data, 0)) != 0)
+		strbuf_ltrim(line);
+		if (!line->len)
+			return 0;
+		if ((still_looking = check_header(line, s_hdr_data, 0)) != 0)
 			return 0;
 	}
 
 	/* normalize the log message to UTF-8. */
 	if (metainfo_charset)
-		convert_to_utf8(line, endline - line, charset);
+		convert_to_utf8(line, charset.buf);
 
 	if (patchbreak(line)) {
 		fclose(cmitmsg);
 		cmitmsg = NULL;
 		return 1;
 	}
 
-	fputs(line, cmitmsg);
+	fputs(line->buf, cmitmsg);
 	return 0;
 }
 
-static int handle_patch(char *line, int len)
+static void handle_patch(const struct strbuf *line)
 {
-	fwrite(line, 1, len, patchfile);
+	fwrite(line->buf, 1, line->len, patchfile);
 	patch_lines++;
-	return 0;
 }
 
-static int handle_filter(char *line, unsigned linesize, int linelen)
+static void handle_filter(struct strbuf *line)
 {
 	static int filter = 0;
 
-	/* filter tells us which part we left off on
-	 * a non-zero return indicates we hit a filter point
-	 */
+	/* filter tells us which part we left off on */
 	switch (filter) {
 	case 0:
-		if (!handle_commit_msg(line, linesize))
+		if (!handle_commit_msg(line))
 			break;
 		filter++;
 	case 1:
-		if (!handle_patch(line, linelen))
-			break;
-		filter++;
-	default:
-		return 1;
+		handle_patch(line);
+		break;
 	}
-
-	return 0;
 }
 
 static void handle_body(void)
 {
-	int rc = 0;
-	static char newline[2000];
-	static char *np = newline;
-	int len = strlen(line);
+	int len = 0;
+	struct strbuf prev = STRBUF_INIT;
 
 	/* Skip up to the first boundary */
-	if (content_top->boundary) {
+	if (*content_top) {
 		if (!find_boundary())
-			return;
+			goto handle_body_out;
 	}
 
 	do {
+		strbuf_setlen(&line, line.len + len);
+
 		/* process any boundary lines */
-		if (content_top->boundary && is_multipart_boundary(line)) {
+		if (*content_top && is_multipart_boundary(&line)) {
 			/* flush any leftover */
-			if (np != newline)
-				handle_filter(newline, sizeof(newline),
-					      np - newline);
+			if (line.len)
+				handle_filter(&line);
+
 			if (!handle_boundary())
-				return;
-			len = strlen(line);
+				goto handle_body_out;
 		}
 
 		/* Unwrap transfer encoding */
-		len = decode_transfer_encoding(line, sizeof(line), len);
-		if (len < 0) {
-			error("Malformed input line");
-			return;
-		}
+		decode_transfer_encoding(&line);
 
 		switch (transfer_encoding) {
 		case TE_BASE64:
 		case TE_QP:
 		{
-			char *op = line;
+			struct strbuf **lines, **it, *sb;
+
+			/* Prepend any previous partial lines */
+			strbuf_insert(&line, 0, prev.buf, prev.len);
+			strbuf_reset(&prev);
 
 			/* binary data most likely doesn't have newlines */
 			if (message_type != TYPE_TEXT) {
-				rc = handle_filter(line, sizeof(line), len);
+				handle_filter(&line);
 				break;
 			}
-
 			/*
 			 * This is a decoded line that may contain
 			 * multiple new lines.  Pass only one chunk
 			 * at a time to handle_filter()
 			 */
-			do {
-				while (op < line + len && *op != '\n')
-					*np++ = *op++;
-				*np = *op;
-				if (*np != 0) {
-					/* should be sitting on a new line */
-					*(++np) = 0;
-					op++;
-					rc = handle_filter(newline, sizeof(newline), np - newline);
-					np = newline;
-				}
-			} while (op < line + len);
+			lines = strbuf_split(&line, '\n');
+			for (it = lines; (sb = *it); it++) {
+				if (*(it + 1) == NULL) /* The last line */
+					if (sb->buf[sb->len - 1] != '\n') {
+						/* Partial line, save it for later. */
+						strbuf_addbuf(&prev, sb);
+						break;
+					}
+				handle_filter(sb);
+			}
 			/*
-			 * The partial chunk is saved in newline and will be
+			 * The partial chunk is saved in "prev" and will be
 			 * appended by the next iteration of read_line_with_nul().
 			 */
+			strbuf_list_free(lines);
 			break;
 		}
 		default:
-			rc = handle_filter(line, sizeof(line), len);
+			handle_filter(&line);
 		}
-		if (rc)
-			/* nothing left to filter */
-			break;
-	} while ((len = read_line_with_nul(line, sizeof(line), fin)));
 
-	return;
+		strbuf_reset(&line);
+		if (strbuf_avail(&line) < 100)
+			strbuf_grow(&line, 100);
+	} while ((len = read_line_with_nul(line.buf, strbuf_avail(&line), fin)));
+
+handle_body_out:
+	strbuf_release(&prev);
 }
 
-static void output_header_lines(FILE *fout, const char *hdr, char *data)
+static void output_header_lines(FILE *fout, const char *hdr, const struct strbuf *data)
 {
+	const char *sp = data->buf;
 	while (1) {
-		char *ep = strchr(data, '\n');
+		char *ep = strchr(sp, '\n');
 		int len;
 		if (!ep)
-			len = strlen(data);
+			len = strlen(sp);
 		else
-			len = ep - data;
-		fprintf(fout, "%s: %.*s\n", hdr, len, data);
+			len = ep - sp;
+		fprintf(fout, "%s: %.*s\n", hdr, len, sp);
 		if (!ep)
 			break;
-		data = ep + 1;
+		sp = ep + 1;
 	}
 }
 
 static void handle_info(void)
 {
-	char *sub;
-	char *hdr;
+	struct strbuf *hdr;
 	int i;
 
 	for (i = 0; header[i]; i++) {
-
 		/* only print inbody headers if we output a patch file */
 		if (patch_lines && s_hdr_data[i])
 			hdr = s_hdr_data[i];
