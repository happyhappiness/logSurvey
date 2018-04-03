 			    split_cmdline_strerror(count));
 		option_count = handle_options(&new_argv, &count, &envchanged);
 		if (envchanged)
-			die("alias '%s' changes environment variables\n"
-				 "You can use '!git' in the alias to do this.",
+			die("alias '%s' changes environment variables.\n"
+				 "You can use '!git' in the alias to do this",
 				 alias_command);
 		memmove(new_argv - option_count, new_argv,
 				count * sizeof(char *));
