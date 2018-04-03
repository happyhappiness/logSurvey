 
 int cmd_help(int argc, const char **argv, const char *prefix)
 {
-	const char *help_cmd = argv[1];
+	int nongit;
 
-	if (argc < 2) {
-		printf("usage: %s\n\n", git_usage_string);
-		list_common_cmds_help();
-		exit(0);
-	}
+	setup_git_directory_gently(&nongit);
+	git_config(git_help_config);
 
-	if (!strcmp(help_cmd, "--all") || !strcmp(help_cmd, "-a")) {
+	argc = parse_options(argc, argv, builtin_help_options,
+			builtin_help_usage, 0);
+
+	if (show_all) {
 		printf("usage: %s\n\n", git_usage_string);
 		list_commands();
+		return 0;
 	}
 
-	else if (!strcmp(help_cmd, "--web") || !strcmp(help_cmd, "-w")) {
-		show_html_page(argc > 2 ? argv[2] : NULL);
-	}
-
-	else if (!strcmp(help_cmd, "--info") || !strcmp(help_cmd, "-i")) {
-		show_info_page(argc > 2 ? argv[2] : NULL);
-	}
-
-	else if (!strcmp(help_cmd, "--man") || !strcmp(help_cmd, "-m")) {
-		show_man_page(argc > 2 ? argv[2] : NULL);
+	if (!argv[0]) {
+		printf("usage: %s\n\n", git_usage_string);
+		list_common_cmds_help();
+		return 0;
 	}
 
-	else {
-		int nongit;
-
-		setup_git_directory_gently(&nongit);
-		git_config(git_help_config);
-		if (help_default_format)
-			parse_help_format(help_default_format);
-
-		switch (help_format) {
-		case man_format:
-			show_man_page(help_cmd);
-			break;
-		case info_format:
-			show_info_page(help_cmd);
-			break;
-		case web_format:
-			show_html_page(help_cmd);
-			break;
-		}
+	switch (help_format) {
+	case HELP_FORMAT_MAN:
+		show_man_page(argv[0]);
+		break;
+	case HELP_FORMAT_INFO:
+		show_info_page(argv[0]);
+		break;
+	case HELP_FORMAT_WEB:
+		show_html_page(argv[0]);
+		break;
 	}
 
 	return 0;