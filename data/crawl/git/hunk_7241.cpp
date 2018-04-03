 
 static void exec_viewer(const char *name, const char *page)
 {
-	const char *path = get_man_viewer_info(name);
+	const char *info = get_man_viewer_info(name);
 
 	if (!strcasecmp(name, "man"))
-		exec_man_man(path, page);
+		exec_man_man(info, page);
 	else if (!strcasecmp(name, "woman"))
-		exec_woman_emacs(path, page);
+		exec_woman_emacs(info, page);
 	else if (!strcasecmp(name, "konqueror"))
-		exec_man_konqueror(path, page);
+		exec_man_konqueror(info, page);
+	else if (info)
+		exec_man_cmd(info, page);
 	else
-		warning("'%s': unsupported man viewer.", name);
+		warning("'%s': unknown man viewer.", name);
 }
 
 static void show_man_page(const char *git_cmd)