 {
 	int ret = 0;
 	struct strbuf buf = STRBUF_INIT;
+	char *expanded = expand_user_path(path);
+
+	if (!expanded)
+		return error("Could not expand include path '%s'", path);
+	path = expanded;
 
 	/*
 	 * Use an absolute path as-is, but interpret relative paths
