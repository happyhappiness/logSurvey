 	char path[PATH_MAX];
 	size_t len = strlen(suspect);
 
+	if (PATH_MAX <= len + strlen("/objects"))
+		die("Too long path: %.*s", 60, suspect);
 	strcpy(path, suspect);
 	if (getenv(DB_ENVIRONMENT)) {
 		if (access(getenv(DB_ENVIRONMENT), X_OK))