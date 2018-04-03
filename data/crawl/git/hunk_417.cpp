 		DIFF_OPT_CLR(options, FUNCCONTEXT);
 	else if ((argcount = parse_long_opt("output", av, &optarg))) {
 		char *path = prefix_filename(prefix, optarg);
-		options->file = fopen(path, "w");
-		if (!options->file)
-			die_errno("Could not open '%s'", path);
+		options->file = xfopen(path, "w");
 		options->close_file = 1;
 		if (options->use_color != GIT_COLOR_ALWAYS)
 			options->use_color = GIT_COLOR_NEVER;
