 			merge_style = git_xmerge_style;
 	}
 
-	while (argc > 4) {
-		if (!strcmp(argv[1], "-L") && i < 3) {
-			names[i++] = argv[2];
-			argc--;
-			argv++;
-		} else if (!strcmp(argv[1], "-p") ||
-				!strcmp(argv[1], "--stdout"))
-			to_stdout = 1;
-		else if (!strcmp(argv[1], "-q") ||
-				!strcmp(argv[1], "--quiet"))
-			freopen("/dev/null", "w", stderr);
-		else if (!strcmp(argv[1], "--diff3"))
-			merge_style = XDL_MERGE_DIFF3;
-		else
-			usage(merge_file_usage);
-		argc--;
-		argv++;
-	}
-
-	if (argc != 4)
-		usage(merge_file_usage);
-
-	for (; i < 3; i++)
-		names[i] = argv[i + 1];
+	argc = parse_options(argc, argv, options, merge_file_usage, 0);
+	if (argc != 3)
+		usage_with_options(merge_file_usage, options);
+	if (quiet)
+		freopen("/dev/null", "w", stderr);
 
 	for (i = 0; i < 3; i++) {
-		if (read_mmfile(mmfs + i, argv[i + 1]))
+		if (!names[i])
+			names[i] = argv[i];
+		if (read_mmfile(mmfs + i, argv[i]))
 			return -1;
 		if (buffer_is_binary(mmfs[i].ptr, mmfs[i].size))
 			return error("Cannot merge binary files: %s\n",
-					argv[i + 1]);
+					argv[i]);
 	}
 
 	ret = xdl_merge(mmfs + 1, mmfs + 0, names[0], mmfs + 2, names[2],
