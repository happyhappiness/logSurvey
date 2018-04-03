 	return error("unknown option `%s'", arg);
 }
 
+void check_typos(const char *arg, const struct option *options)
+{
+	if (strlen(arg) < 3)
+		return;
+
+	if (!prefixcmp(arg, "no-")) {
+		error ("did you mean `--%s` (with two dashes ?)", arg);
+		exit(129);
+	}
+
+	for (; options->type != OPTION_END; options++) {
+		if (!options->long_name)
+			continue;
+		if (!prefixcmp(options->long_name, arg)) {
+			error ("did you mean `--%s` (with two dashes ?)", arg);
+			exit(129);
+		}
+	}
+}
+
 static NORETURN void usage_with_options_internal(const char * const *,
                                                  const struct option *, int);
 
