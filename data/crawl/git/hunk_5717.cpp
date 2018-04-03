 	argc = parse_options(argc, argv, prefix, options, checkout_usage,
 			     PARSE_OPT_KEEP_DASHDASH);
 
+	if (patch_mode && (opts.track > 0 || opts.new_branch
+			   || opts.new_branch_log || opts.merge || opts.force))
+		die ("--patch is incompatible with all other options");
+
 	/* --track without -b should DWIM */
 	if (0 < opts.track && !opts.new_branch) {
 		const char *argv0 = argv[0];
