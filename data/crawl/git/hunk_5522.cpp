 	transport = NULL;
 	return exit_code;
 }
+
+int cmd_fetch(int argc, const char **argv, const char *prefix)
+{
+	int i;
+	struct string_list list = { NULL, 0, 0, 0 };
+	struct remote *remote;
+	int result = 0;
+
+	/* Record the command line for the reflog */
+	strbuf_addstr(&default_rla, "fetch");
+	for (i = 1; i < argc; i++)
+		strbuf_addf(&default_rla, " %s", argv[i]);
+
+	argc = parse_options(argc, argv, prefix,
+			     builtin_fetch_options, builtin_fetch_usage, 0);
+
+	if (all) {
+		if (argc == 1)
+			die("fetch --all does not take a repository argument");
+		else if (argc > 1)
+			die("fetch --all does not make sense with refspecs");
+		(void) for_each_remote(get_one_remote_for_fetch, &list);
+		result = fetch_multiple(&list);
+	} else if (argc == 0) {
+		/* No arguments -- use default remote */
+		remote = remote_get(NULL);
+		result = fetch_one(remote, argc, argv);
+	} else {
+		/* Single remote or group */
+		(void) add_remote_or_group(argv[0], &list);
+		if (list.nr > 1) {
+			/* More than one remote */
+			if (argc > 1)
+				die("Fetching a group and specifying refspecs does not make sense");
+			result = fetch_multiple(&list);
+		} else {
+			/* Zero or one remotes */
+			remote = remote_get(argv[0]);
+			result = fetch_one(remote, argc-1, argv+1);
+		}
+	}
+
+	/* All names were strdup()ed or strndup()ed */
+	list.strdup_strings = 1;
+	string_list_clear(&list, 0);
+
+	return result;
+}
