 {
 	struct git_var *ptr;
 	for (ptr = git_vars; ptr->read; ptr++)
-		printf("%s=%s\n", ptr->name, ptr->read(IDENT_WARN_ON_NO_NAME));
+		printf("%s=%s\n", ptr->name, ptr->read(0));
 }
 
 static const char *read_var(const char *var)