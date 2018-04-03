 		commit_pager_choice();
 		printf("usage: %s\n\n", git_usage_string);
 		list_common_cmds_help();
-		printf("\n%s\n", git_more_info_string);
+		printf("\n%s\n", _(git_more_info_string));
 		exit(1);
 	}
 	cmd = argv[0];