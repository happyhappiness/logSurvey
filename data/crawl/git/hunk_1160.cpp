 	if (!show_only && ignore_missing)
 		die(_("Option --ignore-missing can only be used together with --dry-run"));
 
-	if (!chmod_arg)
-		force_mode = 0;
-	else if (!strcmp(chmod_arg, "-x"))
-		force_mode = 0666;
-	else if (!strcmp(chmod_arg, "+x"))
-		force_mode = 0777;
-	else
+	if (chmod_arg && ((chmod_arg[0] != '-' && chmod_arg[0] != '+') ||
+			  chmod_arg[1] != 'x' || chmod_arg[2]))
 		die(_("--chmod param '%s' must be either -x or +x"), chmod_arg);
 
 	add_new_files = !take_worktree_changes && !refresh_only;