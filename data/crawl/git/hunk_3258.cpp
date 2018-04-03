 		option_commit = 0;
 	}
 
-	if (!abort_current_merge) {
-		if (!argc) {
-			if (default_to_upstream)
-				argc = setup_with_upstream(&argv);
-			else
-				die(_("No commit specified and merge.defaultToUpstream not set."));
-		} else if (argc == 1 && !strcmp(argv[0], "-"))
-			argv[0] = "@{-1}";
+	if (!argc) {
+		if (default_to_upstream)
+			argc = setup_with_upstream(&argv);
+		else
+			die(_("No commit specified and merge.defaultToUpstream not set."));
+	} else if (argc == 1 && !strcmp(argv[0], "-")) {
+		argv[0] = "@{-1}";
 	}
+
 	if (!argc)
 		usage_with_options(builtin_merge_usage,
 			builtin_merge_options);