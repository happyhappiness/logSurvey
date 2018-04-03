 			     builtin_clone_usage, 0);
 
 	if (argc > 2)
-		usage_msg_opt("Too many arguments.",
+		usage_msg_opt(_("Too many arguments."),
 			builtin_clone_usage, builtin_clone_options);
 
 	if (argc == 0)
-		usage_msg_opt("You must specify a repository to clone.",
+		usage_msg_opt(_("You must specify a repository to clone."),
 			builtin_clone_usage, builtin_clone_options);
 
 	if (option_mirror)
 		option_bare = 1;
 
 	if (option_bare) {
 		if (option_origin)
-			die("--bare and --origin %s options are incompatible.",
+			die(_("--bare and --origin %s options are incompatible."),
 			    option_origin);
 		option_no_checkout = 1;
 	}
