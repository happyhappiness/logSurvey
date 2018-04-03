 		if (longest < entlen)
 			longest = entlen;
 
-		add_cmdname(de->d_name + prefix_len, entlen);
+		add_cmdname(cmds, de->d_name + prefix_len, entlen);
 	}
 	closedir(dir);
 
-	printf("git commands available in '%s'\n", exec_path);
-	printf("----------------------------");
-	mput_char('-', strlen(exec_path));
-	putchar('\n');
-	pretty_print_string_list(cmdname, longest);
-	putchar('\n');
+	return longest;
+}
+
+static void list_commands(void)
+{
+	unsigned int longest = 0;
+	unsigned int len;
+	const char *env_path = getenv("PATH");
+	char *paths, *path, *colon;
+	const char *exec_path = git_exec_path();
+
+	if (exec_path)
+		longest = list_commands_in_dir(&main_cmds, exec_path);
+
+	if (!env_path) {
+		fprintf(stderr, "PATH not set\n");
+		exit(1);
+	}
+
+	path = paths = xstrdup(env_path);
+	while (1) {
+		if ((colon = strchr(path, ':')))
+			*colon = 0;
+
+		len = list_commands_in_dir(&other_cmds, path);
+		if (len > longest)
+			longest = len;
+
+		if (!colon)
+			break;
+		path = colon + 1;
+	}
+	free(paths);
+
+	qsort(main_cmds.names, main_cmds.cnt,
+	      sizeof(*main_cmds.names), cmdname_compare);
+	uniq(&main_cmds);
+
+	qsort(other_cmds.names, other_cmds.cnt,
+	      sizeof(*other_cmds.names), cmdname_compare);
+	uniq(&other_cmds);
+	exclude_cmds(&other_cmds, &main_cmds);
+
+	if (main_cmds.cnt) {
+		printf("available git commands in '%s'\n", exec_path);
+		printf("----------------------------");
+		mput_char('-', strlen(exec_path));
+		putchar('\n');
+		pretty_print_string_list(&main_cmds, longest);
+		putchar('\n');
+	}
+
+	if (other_cmds.cnt) {
+		printf("git commands available from elsewhere on your $PATH\n");
+		printf("---------------------------------------------------\n");
+		pretty_print_string_list(&other_cmds, longest);
+		putchar('\n');
+	}
 }
 
 void list_common_cmds_help(void)
