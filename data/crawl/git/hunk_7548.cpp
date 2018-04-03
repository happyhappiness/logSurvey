 	unlink(git_path("MERGE_HEAD"));
 	unlink(git_path("MERGE_MSG"));
 
-	commit_index_files();
+	if (commit_index_files())
+		die ("Repository has been updated, but unable to write\n"
+		     "new_index file. Check that disk is not full or quota is\n"
+		     "not exceeded, and then \"git reset HEAD\" to recover.");
 
 	rerere();
 	run_hook(get_index_file(), "post-commit", NULL);