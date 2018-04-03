 {
 	int quiet = 0;
 	const char *msg = NULL;
+	struct option options[] = {
+		OPT__QUIET(&quiet),
+		OPT_STRING('m', NULL, &msg, "reason", "reason of the update"),
+		OPT_END(),
+	};
 
 	git_config(git_default_config);
-
-	while (1 < argc) {
-		const char *arg = argv[1];
-		if (arg[0] != '-')
-			break;
-		else if (!strcmp("-q", arg))
-			quiet = 1;
-		else if (!strcmp("-m", arg)) {
-			argc--;
-			argv++;
-			if (argc <= 1)
-				break;
-			msg = argv[1];
-			if (!*msg)
-				die("Refusing to perform update with empty message");
-		}
-		else if (!strcmp("--", arg)) {
-			argc--;
-			argv++;
-			break;
-		}
-		else
-			die("unknown option %s", arg);
-		argc--;
-		argv++;
-	}
-
+	argc = parse_options(argc, argv, options, git_symbolic_ref_usage, 0);
+	if (msg &&!*msg)
+		die("Refusing to perform update with empty message");
 	switch (argc) {
-	case 2:
-		check_symref(argv[1], quiet);
+	case 1:
+		check_symref(argv[0], quiet);
 		break;
-	case 3:
-		create_symref(argv[1], argv[2], msg);
+	case 2:
+		create_symref(argv[0], argv[1], msg);
 		break;
 	default:
-		usage(git_symbolic_ref_usage);
+		usage_with_options(git_symbolic_ref_usage, options);
 	}
 	return 0;
 }