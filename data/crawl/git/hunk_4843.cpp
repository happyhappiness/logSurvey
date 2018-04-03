 		die("cannot update HEAD ref");
 	}
 
+	unlink(git_path("CHERRY_PICK_HEAD"));
 	unlink(git_path("MERGE_HEAD"));
 	unlink(git_path("MERGE_MSG"));
 	unlink(git_path("MERGE_MODE"));
