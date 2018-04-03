 		die("Usage: %s <base>... -- <head> <remote> ...\n", argv[0]);
 
 	for (i = 1; i < argc; ++i) {
-		if (!strcmp(argv[i], "--"))
+		if (!strcmp(argv[i], "--")) {
+			bases[bases_count] = NULL;
 			break;
-		if (bases_count < sizeof(bases)/sizeof(*bases))
+		}
+		if (bases_count < ARRAY_SIZE(bases)-1)
 			bases[bases_count++] = argv[i];
+		else
+			warning("Cannot handle more than %zu bases. "
+				"Ignoring %s.", ARRAY_SIZE(bases)-1, argv[i]);
 	}
 	if (argc - i != 3) /* "--" "<head>" "<remote>" */
 		die("Not handling anything other than two heads merge.");
 
 	branch1 = argv[++i];
 	branch2 = argv[++i];
 
-	h1 = get_ref(branch1);
-	h2 = get_ref(branch2);
+	if (get_sha1(branch1, h1))
+		die("Could not resolve ref '%s'", branch1);
+	if (get_sha1(branch2, h2))
+		die("Could not resolve ref '%s'", branch2);
 
 	branch1 = better_branch_name(branch1);
 	branch2 = better_branch_name(branch2);
 
 	if (merge_recursive_verbosity >= 3)
 		printf("Merging %s with %s\n", branch1, branch2);
 
-	index_fd = hold_locked_index(lock, 1);
-
-	for (i = 0; i < bases_count; i++) {
-		struct commit *ancestor = get_ref(bases[i]);
-		ca = commit_list_insert(ancestor, &ca);
-	}
-	clean = merge_recursive(h1, h2, branch1, branch2, ca, &result);
-
-	if (active_cache_changed &&
-	    (write_cache(index_fd, active_cache, active_nr) ||
-	     commit_locked_index(lock)))
-			die ("unable to write %s", get_index_file());
-
-	return clean ? 0: 1;
+	failed = merge_recursive_generic(bases, h1, branch1, h2, branch2);
+	if (failed < 0)
+		return 128; /* die() error code */
+	return failed;
 }
