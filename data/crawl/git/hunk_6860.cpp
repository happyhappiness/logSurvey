 		struct cmdnames *other_cmds)
 {
 	const char *env_path = getenv("PATH");
-	char *paths, *path, *colon;
 	const char *exec_path = git_exec_path();
 
-	if (exec_path)
+	if (exec_path) {
 		list_commands_in_dir(main_cmds, exec_path, prefix);
-
-	if (!env_path) {
-		fprintf(stderr, "PATH not set\n");
-		exit(1);
+		qsort(main_cmds->names, main_cmds->cnt,
+		      sizeof(*main_cmds->names), cmdname_compare);
+		uniq(main_cmds);
 	}
 
-	path = paths = xstrdup(env_path);
-	while (1) {
-		if ((colon = strchr(path, PATH_SEP)))
-			*colon = 0;
-
-		list_commands_in_dir(other_cmds, path, prefix);
+	if (env_path) {
+		char *paths, *path, *colon;
+		path = paths = xstrdup(env_path);
+		while (1) {
+			if ((colon = strchr(path, PATH_SEP)))
+				*colon = 0;
 
-		if (!colon)
-			break;
-		path = colon + 1;
-	}
-	free(paths);
+			list_commands_in_dir(other_cmds, path, prefix);
 
-	qsort(main_cmds->names, main_cmds->cnt,
-	      sizeof(*main_cmds->names), cmdname_compare);
-	uniq(main_cmds);
+			if (!colon)
+				break;
+			path = colon + 1;
+		}
+		free(paths);
 
-	qsort(other_cmds->names, other_cmds->cnt,
-	      sizeof(*other_cmds->names), cmdname_compare);
-	uniq(other_cmds);
+		qsort(other_cmds->names, other_cmds->cnt,
+		      sizeof(*other_cmds->names), cmdname_compare);
+		uniq(other_cmds);
+	}
 	exclude_cmds(other_cmds, main_cmds);
 }
 