 		rename_branch(head, argv[0], rename > 1);
 	else if (rename && (argc == 2))
 		rename_branch(argv[0], argv[1], rename > 1);
-	else if (argc <= 2)
+	else if (argc <= 2) {
+		if (kinds != REF_LOCAL_BRANCH)
+			die("-a and -r options to 'git branch' do not make sense with a branch name");
 		create_branch(head, argv[0], (argc == 2) ? argv[1] : head,
 			      force_create, reflog, track);
-	else
+	} else
 		usage_with_options(builtin_branch_usage, options);
 
 	return 0;
