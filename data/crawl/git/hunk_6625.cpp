 	else if (stdin_paths && doubledash < argc)
 		errstr = "Can't specify files with --stdin";
 	if (errstr) {
-		error (errstr);
+		error("%s", errstr);
 		usage_with_options(check_attr_usage, check_attr_options);
 	}
 
