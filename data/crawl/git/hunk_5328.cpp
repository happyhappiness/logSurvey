 			setenv(GIT_DIR_ENVIRONMENT, getcwd(git_dir, sizeof(git_dir)), 0);
 			if (envchanged)
 				*envchanged = 1;
+		} else if (!strcmp(cmd, "-c")) {
+			if (*argc < 2) {
+				fprintf(stderr, "-c expects a configuration string\n" );
+				usage(git_usage_string);
+			}
+			git_config_parse_parameter((*argv)[1]);
+			(*argv)++;
+			(*argc)--;
 		} else {
 			fprintf(stderr, "Unknown option: %s\n", cmd);
 			usage(git_usage_string);
