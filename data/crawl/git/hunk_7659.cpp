 
 static void emit_line(const char *set, const char *reset, const char *line, int len)
 {
-	if (len > 0 && line[len-1] == '\n')
-		len--;
 	fputs(set, stdout);
 	fwrite(line, len, 1, stdout);
-	puts(reset);
-}
-
-static void emit_line_with_ws(int nparents,
-			      const char *set, const char *reset, const char *ws,
-			      const char *line, int len, unsigned ws_rule)
-{
-	int col0 = nparents;
-	int last_tab_in_indent = -1;
-	int last_space_in_indent = -1;
-	int i;
-	int tail = len;
-	int need_highlight_leading_space = 0;
-	/*
-	 * The line is a newly added line.  Does it have funny leading
-	 * whitespaces?  In indent, SP should never precede a TAB.  In
-	 * addition, under "indent with non tab" rule, there should not
-	 * be more than 8 consecutive spaces.
-	 */
-	for (i = col0; i < len; i++) {
-		if (line[i] == '\t') {
-			last_tab_in_indent = i;
-			if ((ws_rule & WS_SPACE_BEFORE_TAB) &&
-			    0 <= last_space_in_indent)
-				need_highlight_leading_space = 1;
-		}
-		else if (line[i] == ' ')
-			last_space_in_indent = i;
-		else
-			break;
-	}
-	if ((ws_rule & WS_INDENT_WITH_NON_TAB) &&
-	    0 <= last_space_in_indent &&
-	    last_tab_in_indent < 0 &&
-	    8 <= (i - col0)) {
-		last_tab_in_indent = i;
-		need_highlight_leading_space = 1;
-	}
-	fputs(set, stdout);
-	fwrite(line, col0, 1, stdout);
 	fputs(reset, stdout);
-	if (((i == len) || line[i] == '\n') && i != col0) {
-		/* The whole line was indent */
-		emit_line(ws, reset, line + col0, len - col0);
-		return;
-	}
-	i = col0;
-	if (need_highlight_leading_space) {
-		while (i < last_tab_in_indent) {
-			if (line[i] == ' ') {
-				fputs(ws, stdout);
-				putchar(' ');
-				fputs(reset, stdout);
-			}
-			else
-				putchar(line[i]);
-			i++;
-		}
-	}
-	tail = len - 1;
-	if (line[tail] == '\n' && i < tail)
-		tail--;
-	if (ws_rule & WS_TRAILING_SPACE) {
-		while (i < tail) {
-			if (!isspace(line[tail]))
-				break;
-			tail--;
-		}
-	}
-	if ((i < tail && line[tail + 1] != '\n')) {
-		/* This has whitespace between tail+1..len */
-		fputs(set, stdout);
-		fwrite(line + i, tail - i + 1, 1, stdout);
-		fputs(reset, stdout);
-		emit_line(ws, reset, line + tail + 1, len - tail - 1);
-	}
-	else
-		emit_line(set, reset, line + i, len - i);
 }
 
 static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
