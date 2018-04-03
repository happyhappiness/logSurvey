 	return "";
 }
 
-static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
-{
-	int has_trailing_newline, has_trailing_carriage_return;
-
-	has_trailing_newline = (len > 0 && line[len-1] == '\n');
-	if (has_trailing_newline)
-		len--;
-	has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
-	if (has_trailing_carriage_return)
-		len--;
-
-	fputs(set, file);
-	fwrite(line, len, 1, file);
-	fputs(reset, file);
-	if (has_trailing_carriage_return)
-		fputc('\r', file);
-	if (has_trailing_newline)
-		fputc('\n', file);
-}
-
-static int new_blank_line_at_eof(struct emit_callback *ecbdata, const char *line, int len)
-{
-	if (!((ecbdata->ws_rule & WS_BLANK_AT_EOF) &&
-	      ecbdata->blank_at_eof_in_preimage &&
-	      ecbdata->blank_at_eof_in_postimage &&
-	      ecbdata->blank_at_eof_in_preimage <= ecbdata->lno_in_preimage &&
-	      ecbdata->blank_at_eof_in_postimage <= ecbdata->lno_in_postimage))
-		return 0;
-	return ws_blank_line(line + 1, len - 1, ecbdata->ws_rule);
-}
-
-static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
-{
-	const char *ws = diff_get_color(ecbdata->color_diff, DIFF_WHITESPACE);
-	const char *set = diff_get_color(ecbdata->color_diff, DIFF_FILE_NEW);
-
-	if (!*ws)
-		emit_line(ecbdata->file, set, reset, line, len);
-	else if (new_blank_line_at_eof(ecbdata, line, len))
-		/* Blank line at EOF - paint '+' as well */
-		emit_line(ecbdata->file, ws, reset, line, len);
-	else {
-		/* Emit just the prefix, then the rest. */
-		emit_line(ecbdata->file, set, reset, line, 1);
-		ws_check_emit(line + 1, len - 1, ecbdata->ws_rule,
-			      ecbdata->file, set, reset, ws);
-	}
-}
-
 static unsigned long sane_truncate_line(struct emit_callback *ecb, char *line, unsigned long len)
 {
 	const char *cp;
