 		prefix = "";
 
 	if (!lstat(filename, &st))
-		die("Path '%s' exists on disk, but not in '%s'.",
-		    filename, object_name);
+		die("Path '%s' exists on disk, but not in '%.*s'.",
+		    filename, object_name_len, object_name);
 	if (errno == ENOENT || errno == ENOTDIR) {
 		char *fullname = xmalloc(strlen(filename)
 					     + strlen(prefix) + 1);
