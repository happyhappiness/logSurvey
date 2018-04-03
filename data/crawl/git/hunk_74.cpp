 			list_builtins();
 			exit(0);
 		} else {
-			fprintf(stderr, "Unknown option: %s\n", cmd);
+			fprintf(stderr, _("unknown option: %s\n"), cmd);
 			usage(git_usage_string);
 		}
 
