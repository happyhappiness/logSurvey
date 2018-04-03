 		launch_editor(git_path(commit_editmsg), &sb, env);
 	} else if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
 		rollback_index_files();
-		die("could not read commit message\n");
+		die("could not read commit message");
 	}
 	if (run_hook(index_file, "commit-msg", git_path(commit_editmsg))) {
 		rollback_index_files();
