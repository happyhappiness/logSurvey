 		if (safe_create_leading_directories_const(work_tree) < 0)
 			die("could not create leading directories of '%s': %s",
 					work_tree, strerror(errno));
-		if (mkdir(work_tree, 0755))
+		if (!dest_exists && mkdir(work_tree, 0755))
 			die("could not create work tree dir '%s': %s.",
 					work_tree, strerror(errno));
 		set_git_work_tree(work_tree);
