 	rev.verbose_header = 1;
 	rev.show_root_diff = 1;
 	rev.commit_format = get_commit_format("format:%h: %s");
-	rev.always_show_header = 1;
+	rev.always_show_header = 0;
 
 	printf("Created %scommit ", initial_commit ? "initial " : "");
 
-	log_tree_commit(&rev, commit);
-	printf("\n");
+	if (!log_tree_commit(&rev, commit)) {
+		struct strbuf buf = STRBUF_INIT;
+		format_commit_message(commit, "%h: %s", &buf);
+		printf("%s\n", buf.buf);
+		strbuf_release(&buf);
+	}
 }
 
 int git_commit_config(const char *k, const char *v)