 		colopts = 0;
 	}
 
-	if (delete)
+	if (delete) {
+		if (!argc)
+			die(_("branch name required"));
 		return delete_branches(argc, argv, delete > 1, kinds, quiet);
-	else if (list) {
+	} else if (list) {
 		int ret = print_ref_list(kinds, detached, verbose, abbrev,
 					 with_commit, argv);
 		print_columns(&output, colopts, NULL);