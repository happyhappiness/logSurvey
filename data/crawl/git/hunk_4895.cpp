 	}
 
 	if (commit_tree(sb.buf, active_cache_tree->sha1, parents, commit_sha1,
-			fmt_ident(author_name, author_email, author_date,
-				IDENT_ERROR_ON_NO_NAME))) {
+			author_ident.buf)) {
 		rollback_index_files();
 		die("failed to write commit object");
 	}
+	strbuf_release(&author_ident);
 
 	ref_lock = lock_any_ref_for_update("HEAD",
 					   initial_commit ? NULL : head_sha1,