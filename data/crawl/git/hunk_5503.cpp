 
 static const char var_usage[] = "git var [-l | <variable>]";
 
+static const char *editor(int flag)
+{
+	const char *pgm = git_editor();
+
+	if (!pgm && flag & IDENT_ERROR_ON_NO_NAME)
+		die("Terminal is dumb, but EDITOR unset");
+
+	return pgm;
+}
+
 struct git_var {
 	const char *name;
 	const char *(*read)(int);
 };
 static struct git_var git_vars[] = {
 	{ "GIT_COMMITTER_IDENT", git_committer_info },
 	{ "GIT_AUTHOR_IDENT",   git_author_info },
+	{ "GIT_EDITOR", editor },
 	{ "", NULL },
 };
 
 static void list_vars(void)
 {
 	struct git_var *ptr;
+	const char *val;
+
 	for (ptr = git_vars; ptr->read; ptr++)
-		printf("%s=%s\n", ptr->name, ptr->read(0));
+		if ((val = ptr->read(0)))
+			printf("%s=%s\n", ptr->name, val);
 }
 
 static const char *read_var(const char *var)