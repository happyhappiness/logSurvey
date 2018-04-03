 	 * Other cases are errors.
 	 */
 
+	/* Were we asked to do --no-index explicitly? */
+	for (i = 1; i < argc; i++) {
+		if (!strcmp(argv[i], "--")) {
+			i++;
+			break;
+		}
+		if (!strcmp(argv[i], "--no-index"))
+			no_index = DIFF_NO_INDEX_EXPLICIT;
+		if (argv[i][0] != '-')
+			break;
+	}
+
 	prefix = setup_git_directory_gently(&nongit);
+	/*
+	 * Treat git diff with at least one path outside of the
+	 * repo the same as if the command would have been executed
+	 * outside of a git repository.  In this case it behaves
+	 * the same way as "git diff --no-index <a> <b>", which acts
+	 * as a colourful "diff" replacement.
+	 */
+	if (nongit || ((argc == i + 2) &&
+		       (!path_inside_repo(prefix, argv[i]) ||
+			!path_inside_repo(prefix, argv[i + 1]))))
+		no_index = DIFF_NO_INDEX_IMPLICIT;
+
 	gitmodules_config();
 	git_config(git_diff_ui_config, NULL);
 
 	init_revisions(&rev, prefix);
 
-	/* If this is a no-index diff, just run it and exit there. */
-	diff_no_index(&rev, argc, argv, nongit, prefix);
+	if (no_index) {
+		if (argc != i + 2) {
+			if (no_index == DIFF_NO_INDEX_IMPLICIT) {
+				/*
+				 * There was no --no-index and there were not two
+				 * paths. It is possible that the user intended
+				 * to do an inside-repository operation.
+				 */
+				fprintf(stderr, "Not a git repository\n");
+				fprintf(stderr,
+					"To compare two paths outside a working tree:\n");
+			}
+			/* Give the usage message for non-repository usage and exit. */
+			usagef("git diff %s <path> <path>",
+			       no_index == DIFF_NO_INDEX_EXPLICIT ?
+					"--no-index" : "[--no-index]");
+
+		}
+		/* If this is a no-index diff, just run it and exit there. */
+		diff_no_index(&rev, argc, argv, prefix);
+	}
 
 	/* Otherwise, we are doing the usual "git" diff */
 	rev.diffopt.skip_stat_unmatch = !!diff_auto_refresh_index;
