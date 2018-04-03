 		destination = copy_pathspec(dest_path[0], argv, argc, 1);
 	} else {
 		if (argc != 1)
-			usage_with_options(builtin_mv_usage, builtin_mv_options);
+			die("destination '%s' is not a directory", dest_path[0]);
 		destination = dest_path;
 	}
 