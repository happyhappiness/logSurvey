 	return exit_status;
 }
 
+static void warn_pathless_add(const char *option_name, const char *short_name) {
+	/*
+	 * To be consistent with "git add -p" and most Git
+	 * commands, we should default to being tree-wide, but
+	 * this is not the original behavior and can't be
+	 * changed until users trained themselves not to type
+	 * "git add -u" or "git add -A". For now, we warn and
+	 * keep the old behavior. Later, this warning can be
+	 * turned into a die(...), and eventually we may
+	 * reallow the command with a new behavior.
+	 */
+	warning(_("The behavior of 'git add %s (or %s)' with no path argument from a\n"
+		  "subdirectory of the tree will change in Git 2.0 and should not be used anymore.\n"
+		  "To add content for the whole tree, run:\n"
+		  "\n"
+		  "  git add %s :/\n"
+		  "  (or git add %s :/)\n"
+		  "\n"
+		  "To restrict the command to the current directory, run:\n"
+		  "\n"
+		  "  git add %s .\n"
+		  "  (or git add %s .)\n"
+		  "\n"
+		  "With the current Git version, the command is restricted to the current directory."),
+		option_name, short_name,
+		option_name, short_name,
+		option_name, short_name);
+}
+
 int cmd_add(int argc, const char **argv, const char *prefix)
 {
 	int exit_status = 0;
