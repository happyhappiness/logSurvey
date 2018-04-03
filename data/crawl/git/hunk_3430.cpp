 		usage_msg_opt("-l and -d cannot be used together",
 			      git_replace_usage, options);
 
+	if (format && delete)
+		usage_msg_opt("--format and -d cannot be used together",
+			      git_replace_usage, options);
+
 	if (force && (list || delete))
 		usage_msg_opt("-f cannot be used with -d or -l",
 			      git_replace_usage, options);
