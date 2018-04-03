 static void describe_detached_head(char *msg, struct commit *commit)
 {
 	struct strbuf sb = STRBUF_INIT;
+	struct pretty_print_context ctx = {0};
 	parse_commit(commit);
-	pretty_print_commit(CMIT_FMT_ONELINE, commit, &sb, 0, NULL, NULL, 0, 0);
+	pretty_print_commit(CMIT_FMT_ONELINE, commit, &sb, &ctx);
 	fprintf(stderr, "%s %s... %s\n", msg,
 		find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV), sb.buf);
 	strbuf_release(&sb);
