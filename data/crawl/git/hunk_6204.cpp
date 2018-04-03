 	struct stat st;
 
 	len = strlen(path);
-	if (has_symlink_leading_path(len, path))
+	if (has_symlink_leading_path(path, len))
 		return error("'%s' is beyond a symbolic link", path);
 
 	/*
