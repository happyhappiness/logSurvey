 
 void diff_no_index(struct rev_info *revs,
 		   int argc, const char **argv,
-		   int nongit, const char *prefix)
+		   const char *prefix)
 {
 	int i, prefixlen;
-	int no_index = 0;
 	unsigned deprecated_show_diff_q_option_used = 0;
 	const char *paths[2];
 
-	/* Were we asked to do --no-index explicitly? */
-	for (i = 1; i < argc; i++) {
-		if (!strcmp(argv[i], "--")) {
-			i++;
-			break;
-		}
-		if (!strcmp(argv[i], "--no-index"))
-			no_index = 1;
-		if (argv[i][0] != '-')
-			break;
-	}
-
-	if (!no_index && !nongit) {
-		/*
-		 * Inside a git repository, without --no-index.  Only
-		 * when a path outside the repository is given,
-		 * e.g. "git diff /var/tmp/[12]", or "git diff
-		 * Makefile /var/tmp/Makefile", allow it to be used as
-		 * a colourful "diff" replacement.
-		 */
-		if ((argc != i + 2) ||
-		    (path_inside_repo(prefix, argv[i]) &&
-		     path_inside_repo(prefix, argv[i+1])))
-			return;
-	}
-	if (argc != i + 2) {
-		if (!no_index) {
-			/*
-			 * There was no --no-index and there were not two
-			 * paths. It is possible that the user intended
-			 * to do an inside-repository operation.
-			 */
-			fprintf(stderr, "Not a git repository\n");
-			fprintf(stderr,
-				"To compare two paths outside a working tree:\n");
-		}
-		/* Give the usage message for non-repository usage and exit. */
-		usagef("git diff %s <path> <path>",
-		       no_index ? "--no-index" : "[--no-index]");
-	}
-
 	diff_setup(&revs->diffopt);
 	for (i = 1; i < argc - 2; ) {
 		int j;
