 		if (!git_work_tree_cfg) {
 			git_work_tree_cfg = xcalloc(PATH_MAX, 1);
 			if (!getcwd(git_work_tree_cfg, PATH_MAX))
-				die_errno ("Cannot access current working directory");
+				die_errno (_("Cannot access current working directory"));
 		}
 		if (work_tree)
 			set_git_work_tree(make_absolute_path(work_tree));
 		else
 			set_git_work_tree(git_work_tree_cfg);
 		if (access(get_git_work_tree(), X_OK))
-			die_errno ("Cannot access work tree '%s'",
+			die_errno (_("Cannot access work tree '%s'"),
 				   get_git_work_tree());
 	}
 	else {