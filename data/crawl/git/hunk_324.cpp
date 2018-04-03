 	argc = parse_options(argc, argv, prefix, options,
 			     git_interpret_trailers_usage, 0);
 
+	if (opts.only_input && trailers.nr)
+		usage_msg_opt(
+			_("--trailer with --only-input does not make sense"),
+			git_interpret_trailers_usage,
+			options);
+
 	if (argc) {
 		int i;
 		for (i = 0; i < argc; i++)
