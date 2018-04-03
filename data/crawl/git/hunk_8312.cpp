 			handled++;
 		} else if (!prefixcmp(cmd, "--git-dir=")) {
 			setenv(GIT_DIR_ENVIRONMENT, cmd + 10, 1);
+		} else if (!strcmp(cmd, "--work-tree")) {
+			if (*argc < 2) {
+				fprintf(stderr, "No directory given for --work-tree.\n" );
+				usage(git_usage_string);
+			}
+			setenv(GIT_WORK_TREE_ENVIRONMENT, (*argv)[1], 1);
+			(*argv)++;
+			(*argc)--;
+		} else if (!prefixcmp(cmd, "--work-tree=")) {
+			setenv(GIT_WORK_TREE_ENVIRONMENT, cmd + 12, 1);
 		} else if (!strcmp(cmd, "--bare")) {
 			static char git_dir[PATH_MAX+1];
 			setenv(GIT_DIR_ENVIRONMENT, getcwd(git_dir, sizeof(git_dir)), 1);
