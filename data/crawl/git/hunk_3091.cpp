 {
 	struct strbuf sb = STRBUF_INIT;
 	struct pretty_print_context ctx = {0};
-	ctx.date_mode = DATE_NORMAL;
+	ctx.date_mode.type = DATE_NORMAL;
 	format_commit_message(commit, " %m %s", &sb, &ctx);
 	printf("%s\n", sb.buf);
 	strbuf_release(&sb);