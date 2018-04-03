 	int add_errors;
 };
 
+static const char *option_with_implicit_dot;
+static const char *short_option_with_implicit_dot;
+
+static void warn_pathless_add(void)
+{
+	assert(option_with_implicit_dot && short_option_with_implicit_dot);
+
+	/*
+	 * To be consistent with "git add -p" and most Git
+	 * commands, we should default to being tree-wide, but
+	 * this is not the original behavior and can't be
+	 * changed until users trained themselves not to type
+	 * "git add -u" or "git add -A". For now, we warn and
+	 * keep the old behavior. Later, the behavior can be changed
+	 * to tree-wide, keeping the warning for a while, and
+	 * eventually we can drop the warning.
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
+		option_with_implicit_dot, short_option_with_implicit_dot,
+		option_with_implicit_dot, short_option_with_implicit_dot,
+		option_with_implicit_dot, short_option_with_implicit_dot);
+}
+
 static int fix_unmerged_status(struct diff_filepair *p,
 			       struct update_callback_data *data)
 {
