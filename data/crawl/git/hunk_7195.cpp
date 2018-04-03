 
 	strbuf_release(&sb);
 
+	determine_author_info();
+
 	if (use_editor) {
+		char *author_ident;
+		const char *committer_ident;
+
 		if (in_merge)
 			fprintf(fp,
 				"#\n"
