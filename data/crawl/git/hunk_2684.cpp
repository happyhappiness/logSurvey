 		die(_("Could not make %s writable by group"), dir);
 }
 
-static void copy_templates_1(char *path, int baselen,
-			     char *template, int template_baselen,
+static void copy_templates_1(struct strbuf *path, struct strbuf *template,
 			     DIR *dir)
 {
+	size_t path_baselen = path->len;
+	size_t template_baselen = template->len;
 	struct dirent *de;
 
 	/* Note: if ".git/hooks" file exists in the repository being
