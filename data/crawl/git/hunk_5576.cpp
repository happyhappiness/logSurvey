 	prepare_revision_walk(&revs);
 	commit = get_revision(&revs);
 	if (commit) {
+		struct pretty_print_context ctx = {0};
+		ctx.date_mode = DATE_NORMAL;
 		strbuf_release(&buf);
-		format_commit_message(commit, "%an <%ae>", &buf, DATE_NORMAL);
+		format_commit_message(commit, "%an <%ae>", &buf, &ctx);
 		return strbuf_detach(&buf, NULL);
 	}
 	die("No existing author found with '%s'", name);
