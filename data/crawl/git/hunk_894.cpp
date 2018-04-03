 		const char *nargv[] = {"commit", NULL};
 
 		if (orig_argc != 2)
-			usage_msg_opt("--continue expects no arguments",
+			usage_msg_opt(_("--continue expects no arguments"),
 			      builtin_merge_usage, builtin_merge_options);
 
 		if (!file_exists(git_path_merge_head()))