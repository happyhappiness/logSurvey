 
 	if (space < max_cols)
 		cols = max_cols / space;
-	rows = (cmdname_cnt + cols - 1) / cols;
-
-	qsort(cmdname, cmdname_cnt, sizeof(*cmdname), cmdname_compare);
+	rows = (cmds->cnt + cols - 1) / cols;
 
 	for (i = 0; i < rows; i++) {
 		printf("  ");
 
 		for (j = 0; j < cols; j++) {
 			int n = j * rows + i;
 			int size = space;
-			if (n >= cmdname_cnt)
+			if (n >= cmds->cnt)
 				break;
-			if (j == cols-1 || n + rows >= cmdname_cnt)
+			if (j == cols-1 || n + rows >= cmds->cnt)
 				size = 1;
-			printf("%-*s", size, cmdname[n]->name);
+			printf("%-*s", size, cmds->names[n]->name);
 		}
 		putchar('\n');
 	}
 }
 
-static void list_commands(const char *exec_path)
+static unsigned int list_commands_in_dir(struct cmdnames *cmds,
+					 const char *path)
 {
 	unsigned int longest = 0;
 	const char *prefix = "git-";
 	int prefix_len = strlen(prefix);
-	DIR *dir = opendir(exec_path);
+	DIR *dir = opendir(path);
 	struct dirent *de;
 
-	if (!dir || chdir(exec_path)) {
-		fprintf(stderr, "git: '%s': %s\n", exec_path, strerror(errno));
-		exit(1);
-	}
+	if (!dir || chdir(path))
+		return 0;
 
 	while ((de = readdir(dir)) != NULL) {
 		struct stat st;
