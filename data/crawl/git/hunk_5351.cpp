 		usage_with_options(git_notes_usage, options);
 	}
 
+	if (!copy && rewrite_cmd) {
+		error("cannot use --for-rewrite with %s subcommand.", argv[0]);
+		usage_with_options(git_notes_usage, options);
+	}
 	if (!copy && from_stdin) {
 		error("cannot use --stdin with %s subcommand.", argv[0]);
 		usage_with_options(git_notes_usage, options);
 	}
 
 	if (copy) {
 		const char *from_ref;
-		if (from_stdin) {
+		if (from_stdin || rewrite_cmd) {
 			if (argc > 1) {
 				error("too many parameters");
 				usage_with_options(git_notes_usage, options);
 			} else {
-				return notes_copy_from_stdin(force);
+				return notes_copy_from_stdin(force, rewrite_cmd);
 			}
 		}
 		if (argc < 3) {
