 		usage_msg_opt("-f needs some arguments",
 			      git_replace_usage, options);
 
-	return list_replace_refs(argv[0]);
+	return list_replace_refs(argv[0], format);
 }