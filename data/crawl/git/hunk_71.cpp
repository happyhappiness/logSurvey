 				*envchanged = 1;
 		} else if (!strcmp(cmd, "--super-prefix")) {
 			if (*argc < 2) {
-				fprintf(stderr, "No prefix given for --super-prefix.\n" );
+				fprintf(stderr, _("no prefix given for --super-prefix\n" ));
 				usage(git_usage_string);
 			}
 			setenv(GIT_SUPER_PREFIX_ENVIRONMENT, (*argv)[1], 1);
