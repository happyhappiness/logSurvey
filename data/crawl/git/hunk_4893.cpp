 
 	strbuf_release(&sb);
 
-	determine_author_info();
+	/* This checks and barfs if author is badly specified */
+	determine_author_info(author_ident);
 
 	/* This checks if committer ident is explicitly given */
-	git_committer_info(0);
+	strbuf_addstr(&committer_ident, git_committer_info(0));
 	if (use_editor && include_status) {
-		char *author_ident;
-		const char *committer_ident;
-
+		char *ai_tmp, *ci_tmp;
 		if (in_merge)
 			fprintf(fp,
 				"#\n"
