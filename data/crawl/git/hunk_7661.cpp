 		return whitespace_rule_cfg;
 	}
 }
+
+/* The returned string should be freed by the caller. */
+char *whitespace_error_string(unsigned ws)
+{
+	struct strbuf err;
+	strbuf_init(&err, 0);
+	if (ws & WS_TRAILING_SPACE)
+		strbuf_addstr(&err, "Adds trailing whitespace");
+	if (ws & WS_SPACE_BEFORE_TAB) {
+		if (err.len)
+			strbuf_addstr(&err, ", ");
+		strbuf_addstr(&err, "Space in indent is followed by a tab");
+	}
+	if (ws & WS_INDENT_WITH_NON_TAB) {
+		if (err.len)
+			strbuf_addstr(&err, ", ");
+		strbuf_addstr(&err, "Indent more than 8 places with spaces");
+	}
+	return strbuf_detach(&err, NULL);
+}
+
+/* If stream is non-NULL, emits the line after checking. */
+unsigned check_and_emit_line(const char *line, int len, unsigned ws_rule,
+			     FILE *stream, const char *set,
+			     const char *reset, const char *ws)
+{
+	unsigned result = 0;
+	int leading_space = -1;
+	int trailing_whitespace = -1;
+	int trailing_newline = 0;
+	int i;
+
+	/* Logic is simpler if we temporarily ignore the trailing newline. */
+	if (len > 0 && line[len - 1] == '\n') {
+		trailing_newline = 1;
+		len--;
+	}
+
+	/* Check for trailing whitespace. */
+	if (ws_rule & WS_TRAILING_SPACE) {
+		for (i = len - 1; i >= 0; i--) {
+			if (isspace(line[i])) {
+				trailing_whitespace = i;
+				result |= WS_TRAILING_SPACE;
+			}
+			else
+				break;
+		}
+	}
+
+	/* Check for space before tab in initial indent. */
+	for (i = 0; i < len; i++) {
+		if (line[i] == '\t') {
+			if ((ws_rule & WS_SPACE_BEFORE_TAB) &&
+			    (leading_space != -1))
+				result |= WS_SPACE_BEFORE_TAB;
+			break;
+		}
+		else if (line[i] == ' ')
+			leading_space = i;
+		else
+			break;
+	}
+
+	/* Check for indent using non-tab. */
+	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && leading_space >= 8)
+		result |= WS_INDENT_WITH_NON_TAB;
+
+	if (stream) {
+		/* Highlight errors in leading whitespace. */
+		if ((result & WS_SPACE_BEFORE_TAB) ||
+		    (result & WS_INDENT_WITH_NON_TAB)) {
+			fputs(ws, stream);
+			fwrite(line, leading_space + 1, 1, stream);
+			fputs(reset, stream);
+			leading_space++;
+		}
+		else
+			leading_space = 0;
+
+		/* Now the rest of the line starts at leading_space.
+		 * The non-highlighted part ends at trailing_whitespace. */
+		if (trailing_whitespace == -1)
+			trailing_whitespace = len;
+
+		/* Emit non-highlighted (middle) segment. */
+		if (trailing_whitespace - leading_space > 0) {
+			fputs(set, stream);
+			fwrite(line + leading_space,
+			    trailing_whitespace - leading_space, 1, stream);
+			fputs(reset, stream);
+		}
+
+		/* Highlight errors in trailing whitespace. */
+		if (trailing_whitespace != len) {
+			fputs(ws, stream);
+			fwrite(line + trailing_whitespace,
+			    len - trailing_whitespace, 1, stream);
+			fputs(reset, stream);
+		}
+		if (trailing_newline)
+			fputc('\n', stream);
+	}
+	return result;
+}