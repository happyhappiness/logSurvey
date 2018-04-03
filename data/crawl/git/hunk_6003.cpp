 	argc = parse_options(argc, argv, prefix, options, git_replace_usage, 0);
 
 	if (list && delete)
-		usage_with_options(git_replace_usage, options);
+		usage_msg_opt("-l and -d cannot be used together",
+			      git_replace_usage, options);
 
 	if (force && (list || delete))
-		usage_with_options(git_replace_usage, options);
+		usage_msg_opt("-f cannot be used with -d or -l",
+			      git_replace_usage, options);
 
 	/* Delete refs */
 	if (delete) {
 		if (argc < 1)
-			usage_with_options(git_replace_usage, options);
+			usage_msg_opt("-d needs at least one argument",
+				      git_replace_usage, options);
 		return for_each_replace_name(argv, delete_replace_ref);
 	}
 
 	/* Replace object */
 	if (!list && argc) {
 		if (argc != 2)
-			usage_with_options(git_replace_usage, options);
+			usage_msg_opt("bad number of arguments",
+				      git_replace_usage, options);
 		return replace_object(argv[0], argv[1], force);
 	}
 
 	/* List refs, even if "list" is not set */
 	if (argc > 1)
-		usage_with_options(git_replace_usage, options);
+		usage_msg_opt("only one pattern can be given with -l",
+			      git_replace_usage, options);
 	if (force)
-		usage_with_options(git_replace_usage, options);
+		usage_msg_opt("-f needs some arguments",
+			      git_replace_usage, options);
 
 	return list_replace_refs(argv[0]);
 }