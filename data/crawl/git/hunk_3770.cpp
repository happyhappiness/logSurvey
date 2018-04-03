 	open_html(page_path.buf);
 }
 
+static struct {
+	const char *name;
+	const char *help;
+} common_guides[] = {
+	{ "attributes", "Defining attributes per path" },
+	{ "glossary", "A Git glossary" },
+	{ "ignore", "Specifies intentionally untracked files to ignore" },
+	{ "modules", "Defining submodule properties" },
+	{ "revisions", "Specifying revisions and ranges for Git" },
+	{ "tutorial", "A tutorial introduction to Git (for version 1.5.1 or newer)" },
+	{ "workflows", "An overview of recommended workflows with Git"},
+};
+
+static void list_common_guides_help(void)
+{
+	int i, longest = 0;
+
+	for (i = 0; i < ARRAY_SIZE(common_guides); i++) {
+		if (longest < strlen(common_guides[i].name))
+			longest = strlen(common_guides[i].name);
+	}
+
+	puts(_("The common Git guides are:\n"));
+	for (i = 0; i < ARRAY_SIZE(common_guides); i++) {
+		printf("   %s   ", common_guides[i].name);
+		mput_char(' ', longest - strlen(common_guides[i].name));
+		puts(_(common_guides[i].help));
+	}
+	putchar('\n');
+}
+
 int cmd_help(int argc, const char **argv, const char *prefix)
 {
 	int nongit;
