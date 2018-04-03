 	argc--;
 	argv++;
 
+	if (0 <= addremove_explicit)
+		addremove = addremove_explicit;
+	else if (take_worktree_changes && ADDREMOVE_DEFAULT)
+		addremove = 0; /* "-u" was given but not "-A" */
+
 	if (addremove && take_worktree_changes)
 		die(_("-A and -u are mutually incompatible"));
+
+	/*
+	 * Warn when "git add pathspec..." was given without "-u" or "-A"
+	 * and pathspec... contains a directory name.
+	 */
+	if (!take_worktree_changes && addremove_explicit < 0 &&
+	    directory_given(argc, argv))
+		warning(_("In Git 2.0, 'git add <pathspec>...' will also update the\n"
+			  "index for paths removed from the working tree that match\n"
+			  "the given pathspec. If you want to 'add' only changed\n"
+			  "or newly created paths, say 'git add --no-all <pathspec>...'"
+			  " instead."));
+
+	if (!take_worktree_changes && addremove_explicit < 0 && argc)
+		/*
+		 * Turn "git add pathspec..." to "git add -A pathspec..."
+		 * in Git 2.0 but not yet
+		 */
+		; /* addremove = 1; */
+
 	if (!show_only && ignore_missing)
 		die(_("Option --ignore-missing can only be used together with --dry-run"));
 	if (addremove) {
