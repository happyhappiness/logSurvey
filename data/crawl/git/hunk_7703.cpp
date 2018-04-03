 	return 0;
 }
 
+static int stdout_is_tty;
+static int get_colorbool_found;
+static int git_get_colorbool_config(const char *var, const char *value)
+{
+	if (!strcmp(var, get_color_slot))
+		get_colorbool_found =
+			git_config_colorbool(var, value, stdout_is_tty);
+	return 0;
+}
+
+static int get_colorbool(int argc, const char **argv)
+{
+	/*
+	 * git config --get-colorbool <slot> [<stdout-is-tty>]
+	 *
+	 * returns "true" or "false" depending on how <slot>
+	 * is configured.
+	 */
+
+	if (argc == 2)
+		stdout_is_tty = git_config_bool("command line", argv[1]);
+	else if (argc == 1)
+		stdout_is_tty = isatty(1);
+	else
+		usage(git_config_set_usage);
+	get_colorbool_found = 0;
+	get_color_slot = argv[0];
+	git_config(git_get_colorbool_config);
+
+	if (argc == 1) {
+		return get_colorbool_found ? 0 : 1;
+	} else {
+		printf("%s\n", get_colorbool_found ? "true" : "false");
+		return 0;
+	}
+}
+
 int cmd_config(int argc, const char **argv, const char *prefix)
 {
 	int nongit = 0;
