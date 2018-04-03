 		prefix = setup_git_directory();
 	if (p->option & USE_PAGER)
 		setup_pager();
-	if (p->option & NEED_WORK_TREE) {
-		const char *work_tree = get_git_work_tree();
-		const char *git_dir = get_git_dir();
-		if (!is_absolute_path(git_dir))
-			set_git_dir(make_absolute_path(git_dir));
-		if (!work_tree || chdir(work_tree))
-			die("%s must be run in a work tree", p->cmd);
-	}
+	if (p->option & NEED_WORK_TREE)
+		setup_work_tree();
+
 	trace_argv_printf(argv, argc, "trace: built-in: git");
 
 	status = p->fn(argc, argv, prefix);
