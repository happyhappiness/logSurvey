 		fprintf(file, "%s\n\\ No newline at end of file\n", reset);
 }
 
+static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)
+{
+	if (!DIFF_FILE_VALID(one)) {
+		mf->ptr = (char *)""; /* does not matter */
+		mf->size = 0;
+		return 0;
+	}
+	else if (diff_populate_filespec(one, 0))
+		return -1;
+	mf->ptr = one->data;
+	mf->size = one->size;
+	return 0;
+}
+
+static int count_trailing_blank(mmfile_t *mf, unsigned ws_rule)
+{
+	char *ptr = mf->ptr;
+	long size = mf->size;
+	int cnt = 0;
+
+	if (!size)
+		return cnt;
+	ptr += size - 1; /* pointing at the very end */
+	if (*ptr != '\n')
+		; /* incomplete line */
+	else
+		ptr--; /* skip the last LF */
+	while (mf->ptr < ptr) {
+		char *prev_eol;
+		for (prev_eol = ptr; mf->ptr <= prev_eol; prev_eol--)
+			if (*prev_eol == '\n')
+				break;
+		if (!ws_blank_line(prev_eol + 1, ptr - prev_eol, ws_rule))
+			break;
+		cnt++;
+		ptr = prev_eol - 1;
+	}
+	return cnt;
+}
+
+static void check_blank_at_eof(mmfile_t *mf1, mmfile_t *mf2,
+			       struct emit_callback *ecbdata)
+{
+	int l1, l2, at;
+	unsigned ws_rule = ecbdata->ws_rule;
+	l1 = count_trailing_blank(mf1, ws_rule);
+	l2 = count_trailing_blank(mf2, ws_rule);
+	if (l2 <= l1) {
+		ecbdata->blank_at_eof_in_preimage = 0;
+		ecbdata->blank_at_eof_in_postimage = 0;
+		return;
+	}
+	at = count_lines(mf1->ptr, mf1->size);
+	ecbdata->blank_at_eof_in_preimage = (at - l1) + 1;
+
+	at = count_lines(mf2->ptr, mf2->size);
+	ecbdata->blank_at_eof_in_postimage = (at - l2) + 1;
+}
+
+static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
+{
+	int has_trailing_newline, has_trailing_carriage_return;
+
+	has_trailing_newline = (len > 0 && line[len-1] == '\n');
+	if (has_trailing_newline)
+		len--;
+	has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
+	if (has_trailing_carriage_return)
+		len--;
+
+	fputs(set, file);
+	fwrite(line, len, 1, file);
+	fputs(reset, file);
+	if (has_trailing_carriage_return)
+		fputc('\r', file);
+	if (has_trailing_newline)
+		fputc('\n', file);
+}
+
+static int new_blank_line_at_eof(struct emit_callback *ecbdata, const char *line, int len)
+{
+	if (!((ecbdata->ws_rule & WS_BLANK_AT_EOF) &&
+	      ecbdata->blank_at_eof_in_preimage &&
+	      ecbdata->blank_at_eof_in_postimage &&
+	      ecbdata->blank_at_eof_in_preimage <= ecbdata->lno_in_preimage &&
+	      ecbdata->blank_at_eof_in_postimage <= ecbdata->lno_in_postimage))
+		return 0;
+	return ws_blank_line(line + 1, len - 1, ecbdata->ws_rule);
+}
+
+static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
+{
+	const char *ws = diff_get_color(ecbdata->color_diff, DIFF_WHITESPACE);
+	const char *set = diff_get_color(ecbdata->color_diff, DIFF_FILE_NEW);
+
+	if (!*ws)
+		emit_line(ecbdata->file, set, reset, line, len);
+	else if (new_blank_line_at_eof(ecbdata, line, len))
+		/* Blank line at EOF - paint '+' as well */
+		emit_line(ecbdata->file, ws, reset, line, len);
+	else {
+		/* Emit just the prefix, then the rest. */
+		emit_line(ecbdata->file, set, reset, line, 1);
+		ws_check_emit(line + 1, len - 1, ecbdata->ws_rule,
+			      ecbdata->file, set, reset, ws);
+	}
+}
+
 static void emit_rewrite_diff(const char *name_a,
 			      const char *name_b,
 			      struct diff_filespec *one,
