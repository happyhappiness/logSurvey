 
 	else if (!strcmp(help_cmd, "--all") || !strcmp(help_cmd, "-a")) {
 		printf("usage: %s\n\n", git_usage_string);
-		if(exec_path)
-			list_commands(exec_path);
+		list_commands();
 		exit(0);
 	}
 