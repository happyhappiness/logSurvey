 
 	/*
 	 * Warn when "git add pathspec..." was given without "-u" or "-A"
-	 * and pathspec... contains a directory name.
+	 * and pathspec... covers a removed path.
 	 */
-	if (!take_worktree_changes && addremove_explicit < 0 &&
-	    directory_given(argc, argv))
-		warning(_("In Git 2.0, 'git add <pathspec>...' will also update the\n"
-			  "index for paths removed from the working tree that match\n"
-			  "the given pathspec. If you want to 'add' only changed\n"
-			  "or newly created paths, say 'git add --no-all <pathspec>...'"
-			  " instead."));
+	memset(&update_data, 0, sizeof(update_data));
+	if (!take_worktree_changes && addremove_explicit < 0)
+		update_data.warn_add_would_remove = 1;
 
 	if (!take_worktree_changes && addremove_explicit < 0 && argc)
 		/*
