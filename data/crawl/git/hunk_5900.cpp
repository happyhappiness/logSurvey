 	if (!dir)
 		return NULL;
 	if (!getcwd(buffer, size))
-		die("can't find the current directory: %s", strerror(errno));
+		die_errno("can't find the current directory");
 
 	if (!is_absolute_path(dir))
 		dir = make_absolute_path(dir);
