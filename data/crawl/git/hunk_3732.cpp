 		if (verbose)
 			die(_("cannot have both --quiet and --verbose"));
 	}
+	if (show_non_matching && !verbose)
+		die(_("--non-matching is only valid with --verbose"));
 
 	if (stdin_paths) {
 		num_ignored = check_ignore_stdin_paths(prefix);
