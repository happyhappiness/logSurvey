 		/* The user didn't specify a command; give them help */
 		printf("usage: %s\n\n", git_usage_string);
 		list_common_cmds_help();
+		printf("\n%s\n", git_more_info_string);
 		exit(1);
 	}
 	cmd = argv[0];
