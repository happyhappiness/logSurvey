 	strbuf_insert(&sb, 0, reflog_msg, strlen(reflog_msg));
 	strbuf_insert(&sb, strlen(reflog_msg), ": ", 2);
 
-	if (!ref_lock)
+	if (!ref_lock) {
+		rollback_index_files();
 		die("cannot lock HEAD ref");
-	if (write_ref_sha1(ref_lock, commit_sha1, sb.buf) < 0)
+	}
+	if (write_ref_sha1(ref_lock, commit_sha1, sb.buf) < 0) {
+		rollback_index_files();
 		die("cannot update HEAD ref");
+	}
 
 	unlink(git_path("MERGE_HEAD"));
 	unlink(git_path("MERGE_MSG"));
 
-	if (lock_file.filename[0] && commit_locked_index(&lock_file))
-		die("failed to write new index");
+	commit_index_files();
 
 	rerere();
-
-	run_hook(index_file, "post-commit", NULL);
-
+	run_hook(get_index_file(), "post-commit", NULL);
 	if (!quiet)
 		print_summary(prefix, commit_sha1);
 