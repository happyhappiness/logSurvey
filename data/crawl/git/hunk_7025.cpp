 		break;
 	}
 
-	flags = show_merge = 0;
-	for (i = 1; i < argc; i++) {
+	/* Second, deal with arguments and options */
+	flags = 0;
+	for (left = i = 1; i < argc; i++) {
 		const char *arg = argv[i];
 		if (*arg == '-') {
 			int opts;
-			if (!prefixcmp(arg, "--max-count=")) {
-				revs->max_count = atoi(arg + 12);
-				continue;
-			}
-			if (!prefixcmp(arg, "--skip=")) {
-				revs->skip_count = atoi(arg + 7);
-				continue;
-			}
-			/* accept -<digit>, like traditional "head" */
-			if ((*arg == '-') && isdigit(arg[1])) {
-				revs->max_count = atoi(arg + 1);
-				continue;
-			}
-			if (!strcmp(arg, "-n")) {
-				if (argc <= i + 1)
-					die("-n requires an argument");
-				revs->max_count = atoi(argv[++i]);
-				continue;
-			}
-			if (!prefixcmp(arg, "-n")) {
-				revs->max_count = atoi(arg + 2);
-				continue;
-			}
-			if (!prefixcmp(arg, "--max-age=")) {
-				revs->max_age = atoi(arg + 10);
-				continue;
-			}
-			if (!prefixcmp(arg, "--since=")) {
-				revs->max_age = approxidate(arg + 8);
-				continue;
-			}
-			if (!prefixcmp(arg, "--after=")) {
-				revs->max_age = approxidate(arg + 8);
-				continue;
-			}
-			if (!prefixcmp(arg, "--min-age=")) {
-				revs->min_age = atoi(arg + 10);
-				continue;
-			}
-			if (!prefixcmp(arg, "--before=")) {
-				revs->min_age = approxidate(arg + 9);
-				continue;
-			}
-			if (!prefixcmp(arg, "--until=")) {
-				revs->min_age = approxidate(arg + 8);
-				continue;
-			}
+
 			if (!strcmp(arg, "--all")) {
 				handle_refs(revs, flags, for_each_ref);
 				continue;
