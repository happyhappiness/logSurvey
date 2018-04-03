 		warning(warn_unconfigured_deny_msg[i]);
 }
 
+static char *warn_unconfigured_deny_delete_current_msg[] = {
+	"Deleting the current branch can cause confusion by making the next",
+	"'git clone' not check out any file.",
+	"",
+	"You can set 'receive.denyDeleteCurrent' configuration variable to",
+	"'refuse' in the remote repository to disallow deleting the current",
+	"branch.",
+	"",
+	"You can set it to 'ignore' to allow such a delete without a warning.",
+	"",
+	"To make this warning message less loud, you can set it to 'warn'.",
+	"",
+	"Note that the default will change in a future version of git",
+	"to refuse deleting the current branch unless you have the",
+	"configuration variable set to either 'ignore' or 'warn'."
+};
+
+static void warn_unconfigured_deny_delete_current(void)
+{
+	int i;
+	for (i = 0;
+	     i < ARRAY_SIZE(warn_unconfigured_deny_delete_current_msg);
+	     i++)
+		warning(warn_unconfigured_deny_delete_current_msg[i]);
+}
+
 static const char *update(struct command *cmd)
 {
 	const char *name = cmd->ref_name;
