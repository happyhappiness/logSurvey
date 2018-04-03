 	return item->conf.key ? !strncasecmp(tok, item->conf.key, tok_len) : 0;
 }
 
-static int parse_trailer(struct strbuf *tok, struct strbuf *val,
-			 const struct conf_info **conf, const char *trailer)
+/*
+ * Return the location of the first separator in line, or -1 if there is no
+ * separator.
+ */
+static int find_separator(const char *line, const char *separators)
+{
+	int loc = strcspn(line, separators);
+	if (!line[loc])
+		return -1;
+	return loc;
+}
+
+/*
+ * Obtain the token, value, and conf from the given trailer.
+ *
+ * separator_pos must not be 0, since the token cannot be an empty string.
+ *
+ * If separator_pos is -1, interpret the whole trailer as a token.
+ */
+static void parse_trailer(struct strbuf *tok, struct strbuf *val,
+			 const struct conf_info **conf, const char *trailer,
+			 int separator_pos)
 {
-	size_t len;
-	struct strbuf seps = STRBUF_INIT;
 	struct arg_item *item;
 	int tok_len;
 	struct list_head *pos;
 
-	strbuf_addstr(&seps, separators);
-	strbuf_addch(&seps, '=');
-	len = strcspn(trailer, seps.buf);
-	strbuf_release(&seps);
-	if (len == 0) {
-		int l = strlen(trailer);
-		while (l > 0 && isspace(trailer[l - 1]))
-			l--;
-		return error(_("empty trailer token in trailer '%.*s'"), l, trailer);
-	}
-	if (len < strlen(trailer)) {
-		strbuf_add(tok, trailer, len);
+	if (separator_pos != -1) {
+		strbuf_add(tok, trailer, separator_pos);
 		strbuf_trim(tok);
-		strbuf_addstr(val, trailer + len + 1);
+		strbuf_addstr(val, trailer + separator_pos + 1);
 		strbuf_trim(val);
 	} else {
 		strbuf_addstr(tok, trailer);
