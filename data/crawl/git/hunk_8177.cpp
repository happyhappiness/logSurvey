 		break;
 	}
 
-	if (require_work_tree &&
-			(!is_inside_work_tree() || is_inside_git_dir()))
-		die("This operation must be run in a work tree");
+	if (require_work_tree && !is_inside_work_tree()) {
+		const char *work_tree = get_git_work_tree();
+		if (!work_tree || chdir(work_tree))
+			die("This operation must be run in a work tree");
+	}
 
 	pathspec = get_pathspec(prefix, argv + i);
 
