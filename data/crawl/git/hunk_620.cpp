  */
 static void get_commit_info(struct am_state *state, struct commit *commit)
 {
-	const char *buffer, *ident_line, *author_date, *msg;
+	const char *buffer, *ident_line, *msg;
 	size_t ident_len;
 	struct ident_split ident_split;
-	struct strbuf sb = STRBUF_INIT;
 
 	buffer = logmsg_reencode(commit, NULL, get_commit_output_encoding());
 
 	ident_line = find_commit_header(buffer, "author", &ident_len);
 
-	if (split_ident_line(&ident_split, ident_line, ident_len) < 0) {
-		strbuf_add(&sb, ident_line, ident_len);
-		die(_("invalid ident line: %s"), sb.buf);
-	}
+	if (split_ident_line(&ident_split, ident_line, ident_len) < 0)
+		die(_("invalid ident line: %.*s"), (int)ident_len, ident_line);
 
 	assert(!state->author_name);
 	if (ident_split.name_begin) {
-		strbuf_add(&sb, ident_split.name_begin,
-			ident_split.name_end - ident_split.name_begin);
-		state->author_name = strbuf_detach(&sb, NULL);
+		state->author_name =
+			xmemdupz(ident_split.name_begin,
+				 ident_split.name_end - ident_split.name_begin);
 	} else
 		state->author_name = xstrdup("");
 
 	assert(!state->author_email);
 	if (ident_split.mail_begin) {
-		strbuf_add(&sb, ident_split.mail_begin,
-			ident_split.mail_end - ident_split.mail_begin);
-		state->author_email = strbuf_detach(&sb, NULL);
+		state->author_email =
+			xmemdupz(ident_split.mail_begin,
+				 ident_split.mail_end - ident_split.mail_begin);
 	} else
 		state->author_email = xstrdup("");
 
-	author_date = show_ident_date(&ident_split, DATE_MODE(NORMAL));
-	strbuf_addstr(&sb, author_date);
 	assert(!state->author_date);
-	state->author_date = strbuf_detach(&sb, NULL);
+	state->author_date = xstrdup(show_ident_date(&ident_split, DATE_MODE(NORMAL)));
 
 	assert(!state->msg);
 	msg = strstr(buffer, "\n\n");