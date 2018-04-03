 
 	if (squash) {
 		if (!allow_fast_forward)
-			die("You cannot combine --squash with --no-ff.");
+			die(_("You cannot combine --squash with --no-ff."));
 		option_commit = 0;
 	}
 
 	if (!allow_fast_forward && fast_forward_only)
-		die("You cannot combine --no-ff with --ff-only.");
+		die(_("You cannot combine --no-ff with --ff-only."));
 
 	if (!argc)
 		usage_with_options(builtin_merge_usage,
