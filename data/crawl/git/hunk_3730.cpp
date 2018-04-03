 	if (show_non_matching && !verbose)
 		die(_("--non-matching is only valid with --verbose"));
 
+	/* read_cache() is only necessary so we can watch out for submodules. */
+	if (read_cache() < 0)
+		die(_("index file corrupt"));
+
+	memset(&dir, 0, sizeof(dir));
+	dir.flags |= DIR_COLLECT_IGNORED;
+	setup_standard_excludes(&dir);
+
+	path_exclude_check_init(&check, &dir);
 	if (stdin_paths) {
-		num_ignored = check_ignore_stdin_paths(prefix);
+		num_ignored = check_ignore_stdin_paths(&check, prefix);
 	} else {
-		num_ignored = check_ignore(prefix, argv);
+		num_ignored = check_ignore(&check, prefix, argv);
 		maybe_flush_or_die(stdout, "ignore to stdout");
 	}
 
+	clear_directory(&dir);
+	path_exclude_check_clear(&check);
+
 	return !num_ignored;
 }