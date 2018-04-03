 			}
 			(*argv)++;
 			(*argc)--;
+		} else if (!strcmp(cmd, "--list-builtins")) {
+			list_builtins();
+			exit(0);
 		} else {
 			fprintf(stderr, "Unknown option: %s\n", cmd);
 			usage(git_usage_string);
