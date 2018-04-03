 
 void shortlog_add_commit(struct shortlog *log, struct commit *commit)
 {
-	const char *author = NULL, *buffer;
-	struct strbuf buf = STRBUF_INIT;
-	struct strbuf ufbuf = STRBUF_INIT;
-
-	pp_commit_easy(CMIT_FMT_RAW, commit, &buf);
-	buffer = buf.buf;
-	while (*buffer && *buffer != '\n') {
-		const char *eol = strchr(buffer, '\n');
-
-		if (eol == NULL)
-			eol = buffer + strlen(buffer);
-		else
-			eol++;
-
-		if (starts_with(buffer, "author "))
-			author = buffer + 7;
-		buffer = eol;
-	}
-	if (!author) {
+	struct strbuf author = STRBUF_INIT;
+	struct strbuf oneline = STRBUF_INIT;
+	struct pretty_print_context ctx = {0};
+
+	ctx.fmt = CMIT_FMT_USERFORMAT;
+	ctx.abbrev = log->abbrev;
+	ctx.subject = "";
+	ctx.after_subject = "";
+	ctx.date_mode.type = DATE_NORMAL;
+	ctx.output_encoding = get_log_output_encoding();
+
+	format_commit_message(commit, "%an <%ae>", &author, &ctx);
+	/* we can detect a total failure only by seeing " <>" in the output */
+	if (author.len <= 3) {
 		warning(_("Missing author: %s"),
 		    oid_to_hex(&commit->object.oid));
-		return;
-	}
-	if (log->user_format) {
-		struct pretty_print_context ctx = {0};
-		ctx.fmt = CMIT_FMT_USERFORMAT;
-		ctx.abbrev = log->abbrev;
-		ctx.subject = "";
-		ctx.after_subject = "";
-		ctx.date_mode.type = DATE_NORMAL;
-		ctx.output_encoding = get_log_output_encoding();
-		pretty_print_commit(&ctx, commit, &ufbuf);
-		buffer = ufbuf.buf;
-	} else if (*buffer) {
-		buffer++;
+		goto out;
 	}
-	insert_one_record(log, author, !*buffer ? "<none>" : buffer);
-	strbuf_release(&ufbuf);
-	strbuf_release(&buf);
+
+	if (log->user_format)
+		pretty_print_commit(&ctx, commit, &oneline);
+	else
+		format_commit_message(commit, "%s", &oneline, &ctx);
+
+	insert_one_record(log, author.buf, oneline.len ? oneline.buf : "<none>");
+
+out:
+	strbuf_release(&author);
+	strbuf_release(&oneline);
 }
 
 static void get_from_rev(struct rev_info *rev, struct shortlog *log)