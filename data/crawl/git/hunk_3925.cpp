 		die(_("-A and -u are mutually incompatible"));
 	if (!show_only && ignore_missing)
 		die(_("Option --ignore-missing can only be used together with --dry-run"));
-	if ((addremove || take_worktree_changes) && !argc) {
+	if (addremove) {
+		option_with_implicit_dot = "--all";
+		short_option_with_implicit_dot = "-A";
+	}
+	if (take_worktree_changes) {
+		option_with_implicit_dot = "--update";
+		short_option_with_implicit_dot = "-u";
+	}
+	if (option_with_implicit_dot && !argc) {
 		static const char *here[2] = { ".", NULL };
+		if (prefix)
+			warn_pathless_add(option_with_implicit_dot,
+					  short_option_with_implicit_dot);
 		argc = 1;
 		argv = here;
 	}