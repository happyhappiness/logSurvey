  */
 #define NOT_BARE 	(1<<2)
 
-static void handle_internal_command(int argc, const char **argv, char **envp)
+struct cmd_struct {
+	const char *cmd;
+	int (*fn)(int, const char **, const char *);
+	int option;
+};
+
+static int run_command(struct cmd_struct *p, int argc, const char **argv)
+{
+	const char *prefix;
+
+	prefix = NULL;
+	if (p->option & RUN_SETUP)
+		prefix = setup_git_directory();
+	if (p->option & USE_PAGER)
+		setup_pager();
+	if (p->option & NOT_BARE) {
+		if (is_bare_repository() || is_inside_git_dir())
+			die("%s must be run in a work tree", p->cmd);
+	}
+	trace_argv_printf(argv, argc, "trace: built-in: git");
+
+	return p->fn(argc, argv, prefix);
+}
+
+static void handle_internal_command(int argc, const char **argv)
 {
 	const char *cmd = argv[0];
-	static struct cmd_struct {
-		const char *cmd;
-		int (*fn)(int, const char **, const char *);
-		int option;
-	} commands[] = {
+	static struct cmd_struct commands[] = {
 		{ "add", cmd_add, RUN_SETUP | NOT_BARE },
 		{ "annotate", cmd_annotate, RUN_SETUP | USE_PAGER },
 		{ "apply", cmd_apply },
