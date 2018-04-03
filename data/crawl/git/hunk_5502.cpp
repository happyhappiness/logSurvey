 		editor = getenv("EDITOR");
 
 	if (!editor && terminal_is_dumb)
-		return error("terminal is dumb, but EDITOR unset");
+		return NULL;
 
 	if (!editor)
 		editor = "vi";
 
+	return editor;
+}
+
+int launch_editor(const char *path, struct strbuf *buffer, const char *const *env)
+{
+	const char *editor = git_editor();
+
+	if (!editor)
+		return error("Terminal is dumb, but EDITOR unset");
+
 	if (strcmp(editor, ":")) {
 		size_t len = strlen(editor);
 		int i = 0;
