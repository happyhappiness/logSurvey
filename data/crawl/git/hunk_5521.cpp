 			name, transport->url);
 }
 
-int cmd_fetch(int argc, const char **argv, const char *prefix)
+static int get_one_remote_for_fetch(struct remote *remote, void *priv)
+{
+	struct string_list *list = priv;
+	string_list_append(remote->name, list);
+	return 0;
+}
+
+struct remote_group_data {
+	const char *name;
+	struct string_list *list;
+};
+
+static int get_remote_group(const char *key, const char *value, void *priv)
+{
+	struct remote_group_data *g = priv;
+
+	if (!prefixcmp(key, "remotes.") &&
+			!strcmp(key + 8, g->name)) {
+		/* split list by white space */
+		int space = strcspn(value, " \t\n");
+		while (*value) {
+			if (space > 1) {
+				string_list_append(xstrndup(value, space),
+						   g->list);
+			}
+			value += space + (value[space] != '\0');
+			space = strcspn(value, " \t\n");
+		}
+	}
+
+	return 0;
+}
+
+static int add_remote_or_group(const char *name, struct string_list *list)
+{
+	int prev_nr = list->nr;
+	struct remote_group_data g = { name, list };
+
+	git_config(get_remote_group, &g);
+	if (list->nr == prev_nr) {
+		struct remote *remote;
+		if (!remote_is_configured(name))
+			return 0;
+		remote = remote_get(name);
+		string_list_append(remote->name, list);
+	}
+	return 1;
+}
+
+static int fetch_multiple(struct string_list *list)
+{
+	int i, result = 0;
+	const char *argv[] = { "fetch", NULL, NULL, NULL, NULL };
+	int argc = 1;
+
+	if (verbosity >= 2)
+		argv[argc++] = "-v";
+	if (verbosity >= 1)
+		argv[argc++] = "-v";
+	else if (verbosity < 0)
+		argv[argc++] = "-q";
+
+	for (i = 0; i < list->nr; i++) {
+		const char *name = list->items[i].string;
+		argv[argc] = name;
+		if (verbosity >= 0)
+			printf("Fetching %s\n", name);
+		if (run_command_v_opt(argv, RUN_GIT_CMD)) {
+			error("Could not fetch %s", name);
+			result = 1;
+		}
+	}
+
+	return result;
+}
+
+static int fetch_one(struct remote *remote, int argc, const char **argv)
 {
-	struct remote *remote;
 	int i;
 	static const char **refs = NULL;
 	int ref_nr = 0;
 	int exit_code;
 
-	/* Record the command line for the reflog */
-	strbuf_addstr(&default_rla, "fetch");
-	for (i = 1; i < argc; i++)
-		strbuf_addf(&default_rla, " %s", argv[i]);
-
-	argc = parse_options(argc, argv, prefix,
-			     builtin_fetch_options, builtin_fetch_usage, 0);
-
-	if (argc == 0)
-		remote = remote_get(NULL);
-	else
-		remote = remote_get(argv[0]);
-
 	if (!remote)
 		die("Where do you want to fetch from today?");
 
