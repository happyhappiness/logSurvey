 	return normalized;
 }
 
+static int get_color_found;
+static const char *get_color_slot;
+static char parsed_color[COLOR_MAXLEN];
+
+static int git_get_color_config(const char *var, const char *value)
+{
+	if (!strcmp(var, get_color_slot)) {
+		color_parse(value, var, parsed_color);
+		get_color_found = 1;
+	}
+	return 0;
+}
+
+static int get_color(int argc, const char **argv)
+{
+	/*
+	 * grab the color setting for the given slot from the configuration,
+	 * or parse the default value if missing, and return ANSI color
+	 * escape sequence.
+	 *
+	 * e.g.
+	 * git config --get-color color.diff.whitespace "blue reverse"
+	 */
+	const char *def_color = NULL;
+
+	switch (argc) {
+	default:
+		usage(git_config_set_usage);
+	case 2:
+		def_color = argv[1];
+		/* fallthru */
+	case 1:
+		get_color_slot = argv[0];
+		break;
+	}
+
+	get_color_found = 0;
+	parsed_color[0] = '\0';
+	git_config(git_get_color_config);
+
+	if (!get_color_found && def_color)
+		color_parse(def_color, "command line", parsed_color);
+
+	fputs(parsed_color, stdout);
+	return 0;
+}
+
 int cmd_config(int argc, const char **argv, const char *prefix)
 {
 	int nongit = 0;
