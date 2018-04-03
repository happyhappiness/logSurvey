 	header_len = sb.len;
 	if (!no_edit)
 		launch_editor(git_path(commit_editmsg), &sb);
-	else if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0)
+	else if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
+		rollback_index_files();
 		die("could not read commit message\n");
-	if (run_hook(index_file, "commit-msg", git_path(commit_editmsg)))
+	}
+	if (run_hook(index_file, "commit-msg", git_path(commit_editmsg))) {
+		rollback_index_files();
 		exit(1);
+	}
 	stripspace(&sb, 1);
-	if (sb.len < header_len ||
-	    message_is_empty(&sb, header_len))
+	if (sb.len < header_len || message_is_empty(&sb, header_len)) {
+		rollback_index_files();
 		die("* no commit message?  aborting commit.");
+	}
 	strbuf_addch(&sb, '\0');
 	if (is_encoding_utf8(git_commit_encoding) && !is_utf8(sb.buf))
 		fprintf(stderr, commit_utf8_warn);
 
-	if (write_sha1_file(sb.buf, sb.len - 1, commit_type, commit_sha1))
+	if (write_sha1_file(sb.buf, sb.len - 1, commit_type, commit_sha1)) {
+		rollback_index_files();
 		die("failed to write commit object");
+	}
 
 	ref_lock = lock_any_ref_for_update("HEAD",
 					   initial_commit ? NULL : head_sha1,
