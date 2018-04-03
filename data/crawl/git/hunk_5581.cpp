 		    sha1_to_hex(commit->object.sha1));
 	if (log->user_format) {
 		struct strbuf buf = STRBUF_INIT;
-
-		pretty_print_commit(CMIT_FMT_USERFORMAT, commit, &buf,
-			DEFAULT_ABBREV, "", "", DATE_NORMAL, 0);
+		struct pretty_print_context ctx = {0};
+		ctx.abbrev = DEFAULT_ABBREV;
+		ctx.subject = "";
+		ctx.after_subject = "";
+		ctx.date_mode = DATE_NORMAL;
+		pretty_print_commit(CMIT_FMT_USERFORMAT, commit, &buf, &ctx);
 		insert_one_record(log, author, buf.buf);
 		strbuf_release(&buf);
 		return;
