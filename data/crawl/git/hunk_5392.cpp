 static int prune_tmp_object(const char *path, const char *filename)
 {
 	const char *fullpath = mkpath("%s/%s", path, filename);
-	if (expire) {
-		struct stat st;
-		if (lstat(fullpath, &st))
-			return error("Could not stat '%s'", fullpath);
-		if (st.st_mtime > expire)
-			return 0;
-	}
+	struct stat st;
+	if (lstat(fullpath, &st))
+		return error("Could not stat '%s'", fullpath);
+	if (st.st_mtime > expire)
+		return 0;
 	printf("Removing stale temporary file %s\n", fullpath);
 	if (!show_only)
 		unlink_or_warn(fullpath);
