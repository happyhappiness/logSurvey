 	if (show_all) {
 		printf("usage: %s\n\n", git_usage_string);
 		list_commands();
+		printf("%s\n", git_more_info_string);
 		return 0;
 	}
 
 	if (!argv[0]) {
 		printf("usage: %s\n\n", git_usage_string);
 		list_common_cmds_help();
+		printf("\n%s\n", git_more_info_string);
 		return 0;
 	}
 