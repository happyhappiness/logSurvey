 	return 0;
 }
 
+static int get_ref(int argc, const char **argv, const char *prefix)
+{
+	struct option options[] = { OPT_END() };
+	argc = parse_options(argc, argv, prefix, options,
+			     git_notes_get_ref_usage, 0);
+
+	if (argc) {
+		error("too many parameters");
+		usage_with_options(git_notes_get_ref_usage, options);
+	}
+
+	puts(default_notes_ref());
+	return 0;
+}
+
 int cmd_notes(int argc, const char **argv, const char *prefix)
 {
 	int result;
