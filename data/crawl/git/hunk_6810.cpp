 
 int cmd_merge_recursive(int argc, const char **argv, const char *prefix)
 {
-	const char *bases[21];
+	const unsigned char *bases[21];
 	unsigned bases_count = 0;
 	int i, failed;
-	const char *branch1, *branch2;
 	unsigned char h1[20], h2[20];
-	int subtree_merge = 0;
+	struct merge_options o;
+	struct commit *result;
 
+	init_merge_options(&o);
 	if (argv[0]) {
 		int namelen = strlen(argv[0]);
 		if (8 < namelen &&
 		    !strcmp(argv[0] + namelen - 8, "-subtree"))
-			subtree_merge = 1;
+			o.subtree_merge = 1;
 	}
 
-	git_config(merge_recursive_config, NULL);
-	merge_recursive_setup(subtree_merge);
 	if (argc < 4)
 		die("Usage: %s <base>... -- <head> <remote> ...\n", argv[0]);
 
 	for (i = 1; i < argc; ++i) {
-		if (!strcmp(argv[i], "--")) {
-			bases[bases_count] = NULL;
+		if (!strcmp(argv[i], "--"))
 			break;
+		if (bases_count < ARRAY_SIZE(bases)-1) {
+			unsigned char *sha = xmalloc(20);
+			if (get_sha1(argv[i], sha))
+				die("Could not parse object '%s'", argv[i]);
+			bases[bases_count++] = sha;
 		}
-		if (bases_count < ARRAY_SIZE(bases)-1)
-			bases[bases_count++] = argv[i];
 		else
 			warning("Cannot handle more than %zu bases. "
 				"Ignoring %s.", ARRAY_SIZE(bases)-1, argv[i]);
 	}
 	if (argc - i != 3) /* "--" "<head>" "<remote>" */
 		die("Not handling anything other than two heads merge.");
 
-	branch1 = argv[++i];
-	branch2 = argv[++i];
+	o.branch1 = argv[++i];
+	o.branch2 = argv[++i];
 
-	if (get_sha1(branch1, h1))
-		die("Could not resolve ref '%s'", branch1);
-	if (get_sha1(branch2, h2))
-		die("Could not resolve ref '%s'", branch2);
+	if (get_sha1(o.branch1, h1))
+		die("Could not resolve ref '%s'", o.branch1);
+	if (get_sha1(o.branch2, h2))
+		die("Could not resolve ref '%s'", o.branch2);
 
-	branch1 = better_branch_name(branch1);
-	branch2 = better_branch_name(branch2);
+	o.branch1 = better_branch_name(o.branch1);
+	o.branch2 = better_branch_name(o.branch2);
 
-	if (merge_recursive_verbosity >= 3)
-		printf("Merging %s with %s\n", branch1, branch2);
+	if (o.verbosity >= 3)
+		printf("Merging %s with %s\n", o.branch1, o.branch2);
 
-	failed = merge_recursive_generic(bases, h1, branch1, h2, branch2);
+	failed = merge_recursive_generic(&o, h1, h2, bases_count, bases, &result);
 	if (failed < 0)
 		return 128; /* die() error code */
 	return failed;
